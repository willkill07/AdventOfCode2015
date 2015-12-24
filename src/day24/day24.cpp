#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include "io.hpp"
#include "timer.hpp"
#include "util.hpp"

int64_t check (const std::vector <int> & nums, int target) {
  size_t min { 1 };
  while (std::accumulate (nums.rbegin(), nums.rbegin() + ++min, 0) <= target);
  std::vector <size_t> ind (min);
  for (size_t r { min }; true; ind.resize (++r)) {
    util::combination comb { nums.size(), r };
    while (comb.next (ind)) {
      int sum { 0 }; uint64_t prod { 1 };
      for (int index : ind)
        sum += nums [index], prod *= nums [index];
      if (sum == target)
        return prod;
    }
  }
  return 0;
}

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 && strncmp (argv[1], "part2", 5) == 0 };
  const int BUCKETS { part2 ? 4 : 3 };
  std::vector <int> nums;
  std::copy (io::as <int> (std::cin), { }, std::back_inserter (nums));
  int sum { std::accumulate (std::begin (nums), std::end (nums), 0) };
  std::cout << check (nums, sum / BUCKETS) << std::endl;
  return 0;
}
