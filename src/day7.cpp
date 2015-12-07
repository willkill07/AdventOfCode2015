#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <tuple>
#include "timer.hpp"

using Int = std::uint16_t;
using Callback = std::function <Int()>;
using RegexData = std::tuple <Callback, std::string, std::string>;
using Cache = std::map <std::string, Int>;
using Eval = std::map <std::string, RegexData>;

static const std::regex ASSIGN_OP { "(\\w+) -> (\\w+)" };
static const std::regex NOT_OP { "NOT (\\w+) -> (\\w+)" };
static const std::regex BINARY_OP { "(\\w+) (AND|OR|LSHIFT|RSHIFT) (\\w+) -> (\\w+)" };

Cache cache;
Eval lookup;

Int
getValue (std::string value) {
  try {
    return std::stoi (value);
  } catch (...) {
    auto loc = cache.find (value);
    if (loc != std::end (cache))
      return loc->second;
    auto val = std::get <0> (lookup [value])();
    cache.emplace (value, val);
    return val;
  }
}

template <size_t N>
std::string
getID (std::string n) {
  return std::get <N + 1> (lookup [n]);
}

Eval::value_type
parseLine (std::string line) {
  std::smatch data;
  if (std::regex_match (line, data, ASSIGN_OP)) {
    std::string val { data [1] }, out { data [2] };
    return { out, { [out] () -> Int {
          return getValue (getID <0> (out));
        }, val, std::string { } } };
  } else if (std::regex_match (line, data, NOT_OP)) {
    std::string val { data [1] }, out { data [2] };
    return { out, { [out] () -> Int {
          return ~getValue ( getID <0> (out));
        }, val, std::string { } } };
  } else if (std::regex_match (line, data, BINARY_OP)) {
    std::string val1 { data [1] }, op { data [2] }, val2 { data [3] }, out { data [4] };
    return { out, { [out, op] () -> Int {
          Int v1 { getValue (getID <0> (out)) }, v2 { getValue (getID <1> (out)) };
          return ((op.compare ("AND") == 0) ? (v1 & v2) :
                  ((op.compare ("OR") == 0) ? (v1 | v2) :
                   ((op.compare ("LSHIFT") == 0) ? (v1 << v2) :
                    ((v1 >> v2)))));
        }, val1, val2 } };
  } else {
    return std::make_pair (std::string { }, RegexData { });
  }
}

int
main (int argc, char* argv []) {
  Timer t;
  bool part2 { argc == 2 };

  std::string line;
  while (std::getline (std::cin, line))
    lookup.emplace (parseLine (line));
  if (part2)
    cache ["b"] = 956;
  std::cout << getValue ("a") << std::endl;
  return 0;
}
