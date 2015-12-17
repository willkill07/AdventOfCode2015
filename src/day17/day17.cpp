#include <array>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include "timer.hpp"
#include "io.hpp"

const int TARGET { 150 };

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  std::vector <int> con;
  std::copy (std::istream_iterator <int> { std::cin }, { }, std::back_inserter (con));
  std::sort (con.rbegin(), con.rend());
  int size { (int)con.size() };

  std::array <std::vector <int>, TARGET + 1> sums;
  for (auto & s : sums)
    s.resize (size);
  sums [0][0] = 1;

  for (int c : con)
    for (int i { TARGET - c }; i >= 0; --i)
      for (int j { 0 }; j < size; ++j)
        sums[i + c][j + 1] += sums[i][j];

  int sum { 0 };
  for (int v : sums.back())
    if (sum += v, part2 && v != 0 && (sum = v))
      break;

  std::cout << sum << std::endl;
  return 0;
}
