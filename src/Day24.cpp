#include <algorithm>
#include <numeric>
#include <vector>
#include "Solution.hpp"
#include "io.hpp"
#include "util.hpp"

int64_t check (const std::vector <int> & nums, int target) {
  size_t min { 1 };
  while (std::accumulate (std::rbegin(nums), std::rbegin(nums) + min++, 0) <= target);
  std::vector <size_t> ind (min);
  for (size_t r { min }; true; ind.resize (++r)) {
    util::combination comb { nums.size(), r };
    while (comb.next (ind)) {
      int sum { 0 }; uint64_t prod { 1 };
      for (auto && index : ind)
        sum += nums [index], prod *= nums [index];
      if (sum == target)
        return prod;
    }
  }
  return 0;
}

template <> void solve <Day24> (bool part2, std::istream & is, std::ostream & os) {
  const int BUCKETS { part2 ? 4 : 3 };
  std::vector <int> nums;
  std::copy (io::as <int> (is), { }, std::back_inserter (nums));
  int sum { std::accumulate (std::cbegin (nums), std::cend (nums), 0) };
  os << check (nums, sum / BUCKETS) << std::endl;
}
