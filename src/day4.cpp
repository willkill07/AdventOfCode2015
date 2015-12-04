#include <string>
#include <iostream>
#include <algorithm>

#include "md5.hpp"

int
main (int argc, char* argv []) {
  bool part2 { argc == 2 };
  std::string input;
  std::cin >> input;

  int index { 1 };
  while (true) {
    std::string parse { input + std::to_string (index) };
    std::string md5sum { md5 (parse) };
    if ((!part2 && (md5sum.find ("00000") == 0)) ||
        (part2 && (md5sum.find ("000000") == 0))) {
      std::cout << index << std::endl;
      break;
    }
    ++index;
  }
  return 0;
}
