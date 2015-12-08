#include <algorithm>
#include <array>
#include <iostream>
#include <regex>
#include <string>
#include "timer.hpp"

const static std::regex PARSE { "(\\d+)x(\\d+)x(\\d+)" };

using Box = std::array <int, 3>;

Box parseLine (std::string line) {
  std::smatch fields;
  std::regex_search (line, fields, PARSE);
  return Box { { std::stoi (fields [1]), std::stoi (fields [2]), std::stoi (fields [3]) } };
}

int main (int argc, char* argv []) {
  Timer t;
  bool part2 { argc == 2 };
  int total { 0 };
  std::string line;
  while (std::getline (std::cin, line)) {
    Box b { parseLine (line) };
    std::sort (std::begin (b), std::end (b));
    total += ((part2) ? (2 * (b[0] + b[1]) + (b[0] * b[1] * b[2])) : (3 * (b[0] * b[1]) + 2 * b[2] * (b[0] + b[1])));
  }
  std::cout << total << std::endl;
  return 0;
}
