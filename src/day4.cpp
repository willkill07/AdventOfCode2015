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
	if (!part2) {
		while (md5 (input + std::to_string (index)).compare (0, 5, "00000") != 0) {
			++index;
		}
	} else {
		while (md5 (input + std::to_string (index)).compare (0, 6, "000000") != 0) {
			++index;
		}
	}
	std::cout << index << std::endl;
  return 0;
}
