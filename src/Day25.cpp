#include "io.hpp"
#include "Solution.hpp"

uint64_t modExp (uint64_t e, uint64_t b = 252533, uint64_t m = 33554393) {
  uint64_t r, x { 1 };
  while (e != 0) {
    r = e % 2, e /= 2;
    if (r == 1)
      x = (x * b) % m;
    b = (b * b) % m;
  }
  return x;
}

template <> void solve <Day25> (bool part2, std::istream & ifs) {
  if (part2)
    std::cout << "Happy Advent of Code :)" << std::endl;
  else {
    const std::regex PARSE { R"(.*row (\d+), column (\d+).*)" };
    std::smatch m { io::regex_parse (io::as_string (ifs), PARSE) };
    int r { std::stoi (m.str (1)) }, c { std::stoi (m.str (2)) }, target { (r + c - 1) * (r + c - 2) / 2 + c - 1 };
    std::cout << (20151125 * modExp (target) % 33554393) << std::endl;
  }
}
