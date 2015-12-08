#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <tuple>
#include "timer.hpp"

using Int = std::uint16_t;
using Callback = std::function <Int()>;
struct Data {
  Callback fn;
  std::string val1;
  std::string val2;
  Data (std::string v1, std::string v2, Callback f) : fn { f }, val1 { v1 }, val2 { v2 } { }
  Data (std::string v1, Callback f) : Data (v1, { }, f) { };
};
using Cache = std::map <std::string, Int>;
using Eval = std::map <std::string, Data>;

static const std::regex ASSIGN_OP { "(\\w+) -> (\\w+)" };
static const std::regex NOT_OP { "NOT (\\w+) -> (\\w+)" };
static const std::regex BINARY_OP { "(\\w+) (AND|OR|LSHIFT|RSHIFT) (\\w+) -> (\\w+)" };

Cache cache;
Eval lookup;

Int
get (std::string value) {
  try {
    return std::stoi (value);
  } catch (...) {
    auto loc = cache.find (value);
    if (loc != std::end (cache))
      return loc->second;
    auto val = lookup.at (value).fn ();
    cache.emplace (value, val);
    return val;
  }
}

void
parseLine (std::string line, Eval &l) {
  std::smatch m;
  if (std::regex_match (line, m, ASSIGN_OP)) {
    std::string out { m [2] };
    l.emplace (out, Data { m [1], [out, &l] () {
          return get (l.at (out).val1);
        } });
  } else if (std::regex_match (line, m, NOT_OP)) {
    std::string out { m [2] };
    l.emplace (out, Data { m [1], [out, &l] () {
          return ~get (l.at (out).val1);
        } });
  } else if (std::regex_match (line, m, BINARY_OP)) {
    std::string op { m [2] }, out { m [4] };
    l.emplace (out, Data { m [1], m [3], [out, op, &l] () {
          Data & d { l.at (out) };
          return ((op.compare ("AND") == 0) ? (get (d.val1) & get (d.val2)) :
                  ((op.compare ("OR") == 0) ? (get (d.val1) | get (d.val2)) :
                   ((op.compare ("LSHIFT") == 0) ? (get (d.val1) << get (d.val2)) :
                    ((get (d.val1) >> get (d.val2))))));
        } });
  }
}

int
main (int argc, char* argv []) {
  Timer t;
  bool part2 { argc == 2 };
  std::string line;
  while (std::getline (std::cin, line))
    parseLine (line, lookup);
  if (part2)
    cache ["b"] = 956;
  std::cout << get ("a") << std::endl;
  return 0;
}
