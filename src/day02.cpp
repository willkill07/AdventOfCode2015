#include <algorithm>
#include "Solution.hpp"
#include "io.hpp"

Day02::Day02 () : Solution { "day02" } { }

void Day02::solve (bool part2) {
	static const std::regex PARSE { R"((\d+)x(\d+)x(\d+))" };
  int total { 0 }, b[3];
  std::smatch m;
  for (auto line : io::by_line { ifs }) {
    std::regex_search (line, m, PARSE);
    std::transform (++m.begin(), m.end(), b, io::to_int);
    std::sort (b, b + 3);
    total += ((part2) ? (2 * (b[0] + b[1]) + (b[0] * b[1] * b[2])) : (3 * (b[0] * b[1]) + 2 * b[2] * (b[0] + b[1])));
  }
  std::cout << total << std::endl;
}
