#include <iostream>
#include <regex>
#include <string>
#include "io.hpp"
#include "timer.hpp"

uint64_t modExp (uint64_t b, uint64_t e, uint64_t m) {
  uint64_t r, x { 1 };
  while (e != 0) {
    r = e % 2, e /= 2;
    if (r == 1)
      x = (x * b) % m;
    b = (b * b) % m;
  }
  return x;
}

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 && strncmp (argv[1], "part2", 5) == 0 };
  if (part2)
    std::cout << "Happy Advent of Code :)" << std::endl;
  else {
    std::smatch m { io::regex_parse (io::as_string (std::cin), std::regex { R"([^\d\s]+(\d+)[^\d\s]+(\d+)[^\d\s]+)" }) };
    int r { std::stoi (m.str (1)) }, c { std::stoi (m.str (2)) }, target { (r + c - 1) * (r + c - 2) / 2 + c - 1 };
    std::cout << ((20151125 * modExp (252533, target, 33554393)) % 33554393) << std::endl;
  }
  return 0;
}
