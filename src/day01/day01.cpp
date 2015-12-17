#include <iostream>
#include "timer.hpp"
#include "io.hpp"

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  int ud [2] { 0, 0 }, count { 0 };
  for (char c; (!part2 || ud[0] >= ud[1]) && std::cin >> c; ++count)
    ++ud [c - '('];
  std::cout << (!part2 ? ud[0] - ud[1] : count) << std::endl;
  return 0;
}
