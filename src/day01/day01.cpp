#include <iostream>
#include "timer.hpp"
#include "io.hpp"

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  int floor { 0 }, count { 0 };
  for (char c : io::as_string (std::cin)) {
    ++count, floor += (c == ')') ? -1 : 1;
    if (part2 && floor == -1 && (floor = count) == -1)
      break;
  }
  std::cout << floor << std::endl;
  return 0;
}
