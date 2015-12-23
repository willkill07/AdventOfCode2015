#include <array>
#include <iostream>
#include "io.hpp"
#include "timer.hpp"

static std::array <int, 1000000> points;

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  int sum { std::stoi (io::as_string (std::cin)) }, weight { part2 ? 11 : 10 };
  size_t elf { 1 };
  for (; elf <= points.size(); ++elf)
    for (size_t h { elf - 1 }; h < points.size() && (part2 ? h < elf * 50 : true); h += elf)
      points [h] += elf * weight;
  for (elf = 0; points [elf++] < sum; );
  std::cout << elf << std::endl;
  return 0;
}
