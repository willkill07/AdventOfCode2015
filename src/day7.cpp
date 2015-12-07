#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <tuple>
#include <regex>

struct Gate;

using Int = std::uint16_t;
using FnType = std::function < Int (Int, Int)>;
using GateMap = std::map <Int, Gate>;
using Args = std::vector <std::string>;

static const std::map <std::string, FnType> FN_MAP {
  {"ASSIGN", [] (Int a, Int b) -> Int { return a; }},
  {"NOT", [] (Int a, Int b) -> Int { return ~a; }},
  {"AND", [] (Int a, Int b) -> Int { return a & b; }},
  {"OR", [] (Int a, Int b) -> Int { return a | b; }},
  {"LSHIFT", [] (Int a, Int b) -> Int { return a << b; }},
  {"RSHIFT", [] (Int a, Int b) -> Int { return a >> b; }}
};

std::regex ASSIGN_OP { "(\\w+) -> (\\w+)" };
std::regex NOT_OP { "NOT (\\w+) -> (\\w+)" };
std::regex BINARY_OP { "(\\w+) (AND|OR|LSHIFT|RSHIFT) (\\w+) -> (\\w+)" };

Int
toInt (std::string s) {
  if (s.size() == 1) {
    return (Int)s[0];
  } else {
    return (((Int)s[0]) << 8) | ((Int)s[1]);
  }
}

struct
Wire {
  union {
    Int lookup;
    Int value;
  };
  bool isValue;

  Wire () : value { 0 }, isValue { true } { }
  Wire (std::string id) : lookup { toInt (id) }, isValue { false } { }
  Wire (Int val) : value { val }, isValue { true } { }

  Int getValue (GateMap & gates);

  static
  Wire constructFrom (std::string && str) {
    try {
      return Wire { static_cast <Int> (std::stoi (str)) };
    } catch (...) {
      return Wire { str };
    }
  }
};

struct
Gate {
  Wire wire1;
  Wire wire2;
  Int out;
  std::string fn;
  FnType function;
  Int value;
  bool memoized;

  Gate (std::string line) : wire1 { }, wire2 { }, out { 0 }, fn { }, function { }, value { 0 }, memoized { false } {
    std::smatch data;
    if (std::regex_match (line, data, ASSIGN_OP)) {
      wire1 = Wire::constructFrom (data [1]);
      fn = "ASSIGN";
    } else if (std::regex_match (line, data, NOT_OP)) {
      wire1 = Wire::constructFrom (data [1]);
      fn = "NOT";
    } else if (std::regex_match (line, data, BINARY_OP)) {
      wire1 = Wire::constructFrom (data [1]);
      wire2 = Wire::constructFrom (data [3]);
      fn = data [2];
    }
    function = FN_MAP.at (fn);
    out = toInt (data [data.size() - 1]);
  }

  Int
  apply (GateMap & gates) {
    value = function (wire1.getValue (gates), wire2.getValue (gates));
    memoized = true;
    return value;
  }
};

Int
Wire::getValue (GateMap & gates) {
  if (isValue)
    return value;
  auto & loc = gates.find (lookup) -> second;
  if (loc.memoized)
    return loc.value;
  loc.apply (gates);
  return loc.value;
}

int
main (int argc, char* argv []) {
  bool part2 { argc == 2 };

  GateMap gates;
  std::string line;
  while (std::getline (std::cin, line)) {
    Gate g { line };
    gates.emplace ( g.out, g );
  }

  if (part2) {
    gates.find (toInt ("b")) -> second = Gate { "956 -> b" };
  }

  auto & a = gates.at (toInt ("a"));
  std::cout << a.apply (gates) << std::endl;
  return 0;
}
