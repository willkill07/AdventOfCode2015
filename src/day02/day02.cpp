#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include "timer.hpp"
#include "io.hpp"

static const std::regex PARSE { R"((\d+)x(\d+)x(\d+))" };

int main (int argc, char* argv []) {
  bool part2 { argc == 2 && strncmp (argv[1], "part2", 5) == 0 };
  int total { 0 }, b[3];
  std::smatch m;
  for (auto line : io::by_line { std::cin }) {
    std::regex_search (line, m, PARSE);
    std::transform (++m.begin(), m.end(), b, io::to_int);
    std::sort (b, b + 3);
    total += ((part2) ? (2 * (b[0] + b[1]) + (b[0] * b[1] * b[2])) : (3 * (b[0] * b[1]) + 2 * b[2] * (b[0] + b[1])));
  }
  std::cout << total << std::endl;
  return 0;
}
