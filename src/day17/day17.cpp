#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include "timer.hpp"
#include "io.hpp"

bool process (int num, const std::vector <int> & con) {
  int sum { 0 };
  for (int i { 0 }; num != 0; num >>= 1, ++i)
    sum += ((num & 0x1) ? con [i] : 0);
  return (sum == 150);
}

int main (int argc, char* argv[]) {
  bool part2 { argc == 2};
  int valid { 0 };
  std::vector <int> con;
  std::map <int, int> counts;
  std::copy (std::istream_iterator <int> { std::cin }, { }, std::back_inserter (con));
  for (int i = 1; i < (1 << con.size()) - 1; ++i)
    if (process (i, con))
      ++valid, ++counts [__builtin_popcount (i)];
  std::cout << (part2 ? std::begin (counts)->second : valid) << std::endl;
  return 0;
}
