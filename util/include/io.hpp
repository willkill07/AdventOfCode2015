#ifndef _WILLIAM_KILLIAN_IO_HPP_
#define _WILLIAM_KILLIAN_IO_HPP_

#include <iostream>
#include <string>
#include <iterator>
#include <regex>

namespace io {
  namespace detail {
    class line : public std::string {
      friend std::istream & operator>> (std::istream & i, line & l) {
        return std::getline (i, l);
      }
    };
  }

  std::sregex_iterator re_search (const std::string & str, const std::regex & re) {
    return { std::begin (str), std::end (str), re };
  }

  std::string as_string (std::istream& is) {
    return { std::istream_iterator <char> { is }, { } };
  }

  class by_match {
    std::sregex_iterator bi, ei;

  public:
    by_match (const std::string & str, const std::regex & re)
      : bi { re_search (str, re) }, ei { } { }

    std::sregex_iterator begin() {
      return bi;
    }

    std::sregex_iterator end() {
      return ei;
    }
  };

  class by_line {
    std::istream& is;

  public:
    using iter = std::istream_iterator <detail::line>;

    by_line (std::istream & i) : is { i } { }

    iter begin() {
      return { is };
    }

    iter end() {
      return { };
    }
  };

  by_line::iter as_line (std::istream& is) {
    return { is };
  }

  template <typename T>
  class reverser {
    typename T::reverse_iterator b,e;

  public:
    reverser (T& data) : b { data.rbegin() }, e { data.rend() } { }

    typename T::reverse_iterator begin() {
      return b;
    }
    typename T::reverse_iterator begin() const {
      return b;
    }
    typename T::reverse_iterator end() {
      return e;
    }
    typename T::reverse_iterator end() const {
      return e;
    }
  };

  template <typename T>
  std::istream_iterator <T> as (std::istream& is) {
    return { is };
  }

  int to_int (const std::string & s) {
    return std::stoi (s);
  }

  std::smatch regex_parse (const std::string & str, const std::regex re) {
    std::smatch res;
    std::regex_match (str, res, re);
    return std::move (res);
  }

  constexpr uint64_t hash (const char* str) {
    uint64_t ret { 0xCBF29CE484222325ull };
    while(*str) ret ^= *(str++), ret *= 0x100000001B3ull;
    return ret;
  }

  constexpr uint64_t hash (const std::string & str) {
    return hash (str.c_str());
  }
}

constexpr uint64_t operator "" _hash (const char* p, size_t) {
  return io::hash (p);
}

#endif
