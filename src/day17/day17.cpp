#include <array>
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include "timer.hpp"
#include "io.hpp"

const int TARGET { 150 };

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  std::vector <int> con;
  std::array <int, TARGET + 1> best, ways;
  std::fill (std::begin (best), std::end (best), std::numeric_limits <int>::max() - 1);
  std::copy (std::istream_iterator <int> { std::cin }, { }, std::back_inserter (con));
  std::sort (con.rbegin(), con.rend());
  ways[0] = 1, best[0] = 0;
  for (auto c : con)
    for (int rem { TARGET }; rem >= c; --rem)
      if (part2) {
        if (best[rem - c] + 1 < best[rem])
          best[rem] = best[rem-c] + 1, ways[rem] = 0;
        if (best[rem - c] + 1 == best[rem])
          ways[rem] += ways [rem - c];
      } else
        ways[rem] += ways[rem - c];
  std::cout <<  ways [TARGET] << std::endl;
  return 0;
}
