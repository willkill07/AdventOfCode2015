#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include <cstdlib>

struct Gate;

using Int = std::uint16_t;
using FnType = std::function < Int (Int, Int)>;
using GateMap = std::map <Int, Gate>;
using ValueMap = std::map <Int, Int>;
using Args = std::vector <std::string>;

static const std::map <std::string, FnType> FN_MAP {
  {"ASSIGN", [] (Int a, Int b) -> Int { return a; }},
  {"NOT", [] (Int a, Int b) -> Int { return ~a; }},
  {"AND", [] (Int a, Int b) -> Int { return a & b; }},
  {"OR", [] (Int a, Int b) -> Int { return a | b; }},
  {"LSHIFT", [] (Int a, Int b) -> Int { return a << b; }},
  {"RSHIFT", [] (Int a, Int b) -> Int { return a >> b; }}
};

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

  Int getValue (GateMap & gates, ValueMap & values);

  static
  Wire constructFrom (std::string str) {
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
  FnType function;
  std::string fn;
  int count;

  Gate (Args data) : wire1 { }, wire2 { }, out { }, function { }, count { 0 } {
    switch (data.size()) {
    case 3: // Value assign
      wire1 = Wire::constructFrom (data [0]);
      fn = "ASSIGN";
      count = 1;
      break;
    case 4: // Unary op assign
      wire1 = Wire::constructFrom (data [1]);
      fn = data [0];
      count = 1;
      break;
    case 5: // Binary op assign
      wire1 = Wire::constructFrom (data [0]);
      wire2 = Wire::constructFrom (data [2]);
      fn = data [1];
      count = 2;
      break;
    }
    function = FN_MAP.at (fn);
    out = toInt (data.back());
  }

  void
  apply (GateMap & gates, ValueMap & values) {
    values [out] = function (wire1.getValue (gates, values), wire2.getValue (gates, values));
  }
};

Int
Wire::getValue (GateMap & gates, ValueMap & values) {
  if (isValue) {
    return value;
  }
  auto loc = values.find (lookup);
  if (loc != std::end (values)) {
    return loc -> second;
  }
  gates.find (lookup) -> second.apply (gates, values);
  return values.find (lookup) -> second;
}

std::vector <std::string>
split (const std::string & line) {
  std::istringstream iss { line };
  std::vector <std::string> list;
  std::string word;
  while (iss >> word) {
    list.push_back (word);
  }
  return list;
}

int
main (int argc, char* argv []) {
  bool part2 { argc == 2 };

  GateMap gates;
  ValueMap values;

  std::string line;
  while (std::getline (std::cin, line)) {
    auto list = split (line);
    gates.emplace ( toInt (list.back()), list);
  }

  if (part2) {
    gates.find (toInt ("b")) -> second = Gate { split ("956 -> b") };
  }

  Int index { toInt ("a") };
  gates.at (index).apply (gates, values);
  std::cout << values.at (index) << std::endl;
  return 0;
}
