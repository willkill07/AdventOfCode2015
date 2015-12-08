#include <iostream>
#include <map>
#include <string>
#include <regex>
#include "timer.hpp"

static const std::regex ASSIGN_OP { "(\\w+) -> (\\w+)" };
static const std::regex NOT_OP { "NOT (\\w+) -> (\\w+)" };
static const std::regex BINARY_OP { "(\\w+) (AND|OR|LSHIFT|RSHIFT) (\\w+) -> (\\w+)" };

using Int = std::uint16_t;
using Callback = std::function <Int()>;

struct Gate {
  Callback fn;
  std::string val1, val2;
  bool memoized { false };
  Int value;
  Gate (std::string v1, std::string v2, Callback f) : fn { f }, val1 { v1 }, val2 { v2 } { }
  Gate (std::string v1, Callback f) : Gate (v1, { }, f) { };
  Gate (Int val) : memoized { true }, value { val } { };
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
      lookup.emplace (out, Gate { m [1], [&, out] () {
        return get (lookup.at (out).val1);
      } });
    } else if (std::regex_match (line, m, NOT_OP)) {
      std::string out { m [2] };
      lookup.emplace (out, Gate { m [1], [&, out] () {
        return ~get (lookup.at (out).val1);
      } });
    } else if (std::regex_match (line, m, BINARY_OP)) {
      std::string op { m [2] }, out { m [4] };
      lookup.emplace (out, Gate { m [1], m [3], [&, out, op] () {
        Gate & g { lookup.at (out) };
        return ((op.compare ("AND") == 0) ? (get (g.val1) & get (g.val2)) :
                ((op.compare ("OR") == 0) ? (get (g.val1) | get (g.val2)) :
                 ((op.compare ("LSHIFT") == 0) ? (get (g.val1) << get (g.val2)) :
                  ((get (g.val1) >> get (g.val2))))));
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
