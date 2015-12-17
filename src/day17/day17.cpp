#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <utility>
#include "timer.hpp"
#include "io.hpp"

const int TARGET { 150 };

int count (const std::vector <int> & c) {
  std::vector <int> dp (TARGET + 1); dp [0] = 1;
  for (int n : c)
    for (int i { TARGET }; i >= n;  dp [i--] += dp [i - n]);
  return dp [TARGET];
}

int min (const std::vector <int> & c) {
  int res { 0 }, size { (int)c.size() };
  static std::vector <int> b (size);
  for (int k { 1 }; k <= size; ++k) {
    std::fill (std::begin (b), std::end (b), 0), std::fill (std::begin (b), std::begin (b) + k, 1);
    do {
      res += (!std::inner_product (std::begin (c), std::end (c), std::begin (b), -TARGET));
    } while (std::prev_permutation (std::begin (b), std::end (b)));
    if (res) break;
  }
  return res;
}

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  std::vector <int> c;
  std::copy (std::istream_iterator <int> { std::cin }, { }, std::back_inserter (c));
  std::cout << (part2 ? min (c) : count (c)) << std::endl;
  return 0;
}
