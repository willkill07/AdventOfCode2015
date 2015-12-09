#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#include "timer.hpp"

using City = std::string;
using Road = std::pair <City, City>;
using FnType = int const & (*)(int const &, int const &);

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  std::map <Road, int> dist;
  std::set <City> p;
  City c1, c2, junk;
  int val;
  while (std::cin >> c1 >> junk >> c2 >> junk >> val) {
    p.insert (c1);
    p.insert (c2);
    dist.emplace (std::minmax (c1, c2), val);
  }
  std::vector <City> order { std::begin (p), std::end (p) };
  int d { part2 ? 0 : std::numeric_limits <int>::max() };
  FnType f { part2 ? (FnType)std::max <int> : (FnType)std::min <int> };
  do {
    auto prev = std::begin (order);
    d = f (d, std::accumulate (prev + 1, std::end (order), 0, [&] (int sum, const City & a) {
      return sum + dist.at (std::minmax (a, *(prev++)));
    }));
  } while (std::next_permutation (std::begin (order), std::end (order)));
  std::cout << d << std::endl;
  return 0;
}
