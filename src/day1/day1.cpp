#include <iostream>
#include "timer.hpp"

int main (int argc, char* argv[]) {
  Timer t;
  bool part2 { argc == 2 };
  int floor { 0 }, count { 0 };
  char c;
  while (std::cin >> c) {
    ++count;
    floor += (c == ')') ? -1 : 1;
    if (part2 && floor == -1) {
      std::cout << count << std::endl;
      return 0;
    }
  }
  std::cout << floor << std::endl;
  return 0;
}
