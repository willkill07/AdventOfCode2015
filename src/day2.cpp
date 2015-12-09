#include <algorithm>
#include <array>
#include <iostream>
#include <regex>
#include <string>
#include "timer.hpp"

static const std::regex PARSE { "(\\d+)x(\\d+)x(\\d+)" };

using Box = std::array <int, 3>;

void parseLine (std::string line, Box &b) {
  std::smatch m;
  std::regex_search (line, m, PARSE);
	std::transform (++m.begin(), m.end(), b.begin(), [] (const auto &o) { return std::stoi (o); });
	std::sort (b.begin(), b.end());
}

int main (int argc, char* argv []) {
  Timer t;
  bool part2 { argc == 2 };
  int total { 0 };
	Box b;
	std::string line;
  while (std::getline (std::cin, line)) {
		parseLine (line, b);
    total += ((part2) ? (2 * (b[0] + b[1]) + (b[0] * b[1] * b[2])) : (3 * (b[0] * b[1]) + 2 * b[2] * (b[0] + b[1])));
  }
  std::cout << total << std::endl;
  return 0;
}
