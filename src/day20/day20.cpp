#include <iostream>
#include <vector>
#include "io.hpp"
#include "timer.hpp"

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  int sum { std::stoi (io::as_string (std::cin)) };
  int i { 1 }, low { 1 }, high { 1 }, weight { part2 ? 11 : 10 };
  while (high * weight <= sum)
    low *= i, high *= (++i);
  long size { high - low };
  std::vector <int> points (size);
  for (int elf { i }; elf < high; ++elf) {
    int o { (low % elf) ? elf - low % elf : 0 };
    for (int h { o }; (part2 ? (h + low) <= (elf * 50) && h < size : h < size); h += elf)
      points [h] += elf * weight;
    if (points [o] >= sum) {
      std::cout << elf << std::endl;
      break;
    }
  }
  return 0;
}
