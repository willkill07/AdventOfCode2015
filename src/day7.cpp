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

  Wire ();
  Wire (std::string);
  Wire (Int);

  Int getValue (GateMap & gates, ValueMap & values);
};

Wire::Wire () : lookup { 0 }, isValue { false } { }
Wire::Wire (std::string id) : lookup { toInt (id) }, isValue { false } { }
Wire::Wire (Int val) : value { val }, isValue { true } { }

struct
Gate {
  Wire wire1;
  Wire wire2;
  Int out;
  FnType function;
  std::string fn;
  int count;

  Gate (Args);
  void apply (GateMap &, ValueMap &);
};


Int
Wire::getValue (GateMap & gates, ValueMap & values) {
  if (isValue) {
    return value;
  }
  auto loc = values.find (lookup);
  if (loc != std::end (values)) {
    return loc->second;
  }
  gates.find (lookup)->second.apply (gates, values);
  return values.find (lookup)->second;
}

void
constructFrom (std::string str, Wire & w) {
  try {
    w = std::move (Wire { static_cast <Int> (std::stoi (str)) });
  } catch (...) {
    w = std::move (Wire { str });
  }
}

Gate::Gate (Args data) : wire1 { }, wire2 { }, out { }, function { }, count { 0 } {
  switch (data.size()) {
  case 3: // Value assign
    constructFrom (data [0], wire1);
    function = [] (Int a, Int b) -> Int { return a; };
    fn = "Assign";
    count = 1;
    break;
  case 4: // Unary op assign
    constructFrom (data [1], wire1);
    function = [] (Int a, Int b) -> Int { return ~a; };
    fn = data [0];
    count = 1;
    break;
  case 5: // Binary op assign
    constructFrom (data [0], wire1);
    constructFrom (data [2], wire2);
    fn = data [1];
    if (fn.compare ("AND") == 0)
      function = [] (Int a, Int b) -> Int { return a & b; };
    else if (fn.compare ("OR") == 0)
      function = [] (Int a, Int b) -> Int { return a | b; };
    else if (fn.compare ("LSHIFT") == 0)
      function = [] (Int a, Int b) -> Int { return a << b; };
    else if (fn.compare ("RSHIFT") == 0)
      function = [] (Int a, Int b) -> Int { return a >> b; };
    count = 2;
    break;
  }
  out = toInt (data.back());
}

void
Gate::apply (GateMap & gates, ValueMap & values) {
  if (count == 1) {
    values [out] = function (wire1.getValue (gates, values), Int { });
  } else {
    values [out] = function (wire1.getValue (gates, values), wire2.getValue (gates, values));
  }
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
    gates.erase (toInt ("b"));
    gates.emplace (toInt ("b"), split ("956 -> b"));
  }

  Int index { toInt ("a") };
  gates.at (index).apply (gates, values);
  std::cout << values.at (index) << std::endl;
  return 0;
}
