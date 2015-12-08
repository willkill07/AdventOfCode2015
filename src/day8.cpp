#include <string>
#include <iostream>
#include <regex>
#include "timer.hpp"

static const std::regex REDUCE { "(\\\\\\\\|\\\\\")" };
static const std::regex HEX { "\\\\x[0-9a-f]{2}" };
static const std::regex EXPAND { "(\"|\\\\)" };

using sIter = std::sregex_iterator;

int
main (int argc, char* argv[]) {
  Timer t;
  bool part2 { argc == 2 };
  int count { 0 };
  std::string s;
  while (std::cin >> s) {
		count += 2;
		if (!part2) {
			count += std::distance (sIter { std::begin (s), std::end (s), REDUCE }, sIter { });
			count += 3 * std::distance (sIter { std::begin (s), std::end (s), HEX }, sIter { });
		} else {
			count += std::distance (sIter { std::begin (s), std::end (s), EXPAND }, sIter { });
		}
	}
  std::cout << count << std::endl;
  return 0;
}
