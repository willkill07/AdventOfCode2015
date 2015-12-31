#ifndef _WILLIAM_KILLIAN_IO_HPP_
#define _WILLIAM_KILLIAN_IO_HPP_

#include <iostream>
#include <string>
#include <iterator>
#include <regex>

namespace io {
  namespace detail {
    class line : public std::string {
      friend std::istream & operator>> (std::istream & i, line & l);
    };
  }

  std::sregex_iterator re_search (const std::string & str, const std::regex & re);

  std::string as_string (std::istream& is);

  class by_match {
    std::sregex_iterator bi, ei;

  public:
    by_match (const std::string & str, const std::regex & re);
    std::sregex_iterator begin();
    std::sregex_iterator end();
  };

  class by_line {
    std::istream& is;
  public:
    using iter = std::istream_iterator <detail::line>;
    by_line (std::istream & i);
    iter begin();
    iter end();
  };

  by_line::iter as_line (std::istream& is);

  template <typename T>
  class reverser_impl {
    typename T::reverse_iterator b,e;

  public:
    reverser_impl (T& data) : b { data.rbegin() }, e { data.rend() } { }

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
  reverser_impl <T> reverser (T& data) {
    return { data };
  }

  template <typename T>
  std::istream_iterator <T> as (std::istream& is) {
    return { is };
  }

  int to_int (const std::string & s);

  std::smatch regex_parse (const std::string & str, const std::regex re);
}

#endif
