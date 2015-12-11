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
  std::istream_iterator <T> as (std::istream& is) {
    return { is };
  }

  int to_int (const std::string & s) {
    return std::stoi (s);
  }
}

#endif
