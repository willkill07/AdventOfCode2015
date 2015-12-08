#include <iostream>
#include <numeric>
#include <regex>
#include <string>
#include "timer.hpp"

static const std::regex REDUCE { "\\\\(\\\\|\"|x[0-9a-f]{2})" };
static const std::regex EXPAND { "(\"|\\\\)" };
using SI = std::sregex_iterator;

int
main (int argc, char* argv[]) {
  Timer t;
  bool part2 { argc == 2 };
  int count { 0 };
  std::string s;
  while (std::cin >> s) {
    if (!part2) {
      count += std::accumulate (SI { s.begin(), s.end(), REDUCE }, { }, 2, [](auto v, auto &s) { return v + s.length() - 1; });
    } else {
      count += 2 + std::distance (SI { s.begin(), s.end(), EXPAND }, { });
    }
  }
  std::cout << count << std::endl;
  return 0;
}
