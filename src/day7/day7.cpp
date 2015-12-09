#include <iostream>
#include <map>
#include <string>
#include <regex>
#include "timer.hpp"

static const std::regex ASSIGN_OP { R"((\w+) -> (\w+))" };
static const std::regex NOT_OP { R"(NOT (\w+) -> (\w+))" };
static const std::regex BINARY_OP { R"((\w+) (AND|OR|(L|R)SHIFT) (\w+) -> (\w+))" };

using Int = std::uint16_t;
using Callback = std::function <Int()>;

struct Gate {
  Callback fn;
  std::string wire1, wire2;
  bool memoized { false };
  Int value;
  Gate (std::string w1, std::string w2, Callback f) : fn { f }, wire1 { w1 }, wire2 { w2 } { }
  Gate (std::string w1, Callback f) : Gate (w1, { }, f) { };
  Gate (Int v) : memoized { true }, value { v } { };
};

struct Circuit {
  std::map <std::string, Gate> lookup;

  void set (std::string key, Int v) {
    lookup.at (key) = Gate { v };
  }

  Int get (std::string value) {
    try {
      return std::stoi (value);
    } catch (...) {
      auto & d = lookup.at (value);
      if (d.memoized)
        return d.value;
      d.value = d.fn();
      d.memoized = true;
      return d.value;
    }
  }

  void parseLine (std::string line) {
    std::smatch m;
    if (std::regex_match (line, m, ASSIGN_OP)) {
      std::string out { m [2] };
      lookup.emplace (out, Gate { m[1], [&, out] () {
        return get (lookup.at (out).wire1);
      } });
    } else if (std::regex_match (line, m, NOT_OP)) {
      std::string out { m[2] };
      lookup.emplace (out, Gate { m[1], [&, out] () {
        return ~get (lookup.at (out).wire1);
      } });
    } else if (std::regex_match (line, m, BINARY_OP)) {
      std::string op { m[2] }, out { m[5] };
      lookup.emplace (out, Gate { m[1], m[4], [&, out, op] () {
        Gate & g { lookup.at (out) };
        return ((op == "AND") ? (get (g.wire1) & get (g.wire2)) :
                ((op == "OR") ? (get (g.wire1) | get (g.wire2)) :
                 ((op == "LSHIFT") ? (get (g.wire1) << get (g.wire2)) :
                  ((get (g.wire1) >> get (g.wire2))))));
      } });
    }
  }
};

int main (int argc, char* argv []) {
  Timer t;
  bool part2 { argc == 2 };
  Circuit c;
  std::string line;
  while (std::getline (std::cin, line))
    c.parseLine (line);
  if (part2)
    c.set ("b", 956);
  std::cout << c.get ("a") << std::endl;
  return 0;
}
