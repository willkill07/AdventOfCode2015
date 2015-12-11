#include <iostream>
#include <limits>
#include <unordered_map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#include "timer.hpp"

using FnType = int const & (*)(int const &, int const &);

static std::hash <std::string> hash;

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  FnType f { part2 ? (FnType)std::max <int> : (FnType)std::min <int> };
  std::unordered_map <size_t, int> dist;
  std::set <size_t> p;

  int d { part2 ? 0 : std::numeric_limits <int>::max() }, val;
  std::string c1, c2, junk;
  while (std::cin >> c1 >> junk >> c2 >> junk >> val) {
    size_t h1 { hash (c1) }, h2 { hash (c2) };
    p.insert (h1), p.insert (h2), dist.emplace (h1 ^ h2, val);
  }

  std::vector <size_t> order { std::begin (p), std::end (p) };
  do {
    auto prev = std::begin (order);
    d = f (d, std::accumulate (prev + 1, std::end (order), 0, [&] (int sum, size_t a) {
      return sum + dist.at (a ^ *(prev++));
    }));
  } while (std::next_permutation (std::begin (order), std::end (order)));
  std::cout << d << std::endl;
  return 0;
}
