#include <iostream>
#include "timer.hpp"
#include "io.hpp"

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  int ud [2] { 0, 0 };
  char c;
  if (!part2) {
    for (int count { 1 }; std::cin >> c; ++count, ++ud [c - '(']);
    std::cout << (ud[0] - ud[1]) << std::endl;
  } else {
    for (int count { 1 }; std::cin >> c; ++count) {
      if (++ud [c - '('], ud[0] < ud[1]) {
        std::cout << count << std::endl;
        break;
      }
    }
  }
  return 0;
}
