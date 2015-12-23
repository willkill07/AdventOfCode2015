#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include "md5.hpp"
#include "timer.hpp"
#include "io.hpp"

const int CHUNK { 100 }, THREADS { 2 };

int main (int argc, char* argv []) {
  bool part2 { argc == 2 };
  std::string input { io::as_string (std::cin) };
	int index { 0 }, off { 0 };
	while ((part2 && off < 6) || (!part2 && off < 5))
		off = md5 (input + std::to_string (++index)).find_first_not_of ('0');
	std::cout << index << std::endl;
  return 0;
}
