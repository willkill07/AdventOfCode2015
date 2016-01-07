#include "Solution.hpp"

template <> void solve <Day01> (bool part2, std::istream & is, std::ostream & os) {
  int ud [2] { 0, 0 }, count { 0 };
  for (char c; (!part2 || ud[0] >= ud[1]) && is >> c; ++count)
    ++ud [c - '('];
  os << (!part2 ? ud[0] - ud[1] : count) << std::endl;
}
