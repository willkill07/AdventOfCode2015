#include "Solution.hpp"

Day01::Day01 () : Solution { "day01" } { }

void Day01::solve (bool part2) {
  int ud [2] { 0, 0 }, count { 0 };
  for (char c; (!part2 || ud[0] >= ud[1]) && ifs >> c; ++count)
    ++ud [c - '('];
  std::cout << (!part2 ? ud[0] - ud[1] : count) << std::endl;
}
