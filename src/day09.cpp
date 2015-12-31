#include <limits>
#include <numeric>
#include <set>
#include <unordered_map>
#include <vector>
#include "Solution.hpp"
#include "io.hpp"
#include "util.hpp"

using FnType = int const & (*)(int const &, int const &);

Day09::Day09 () : Solution { "day09" } { }

void Day09::solve (bool part2) {
	static const std::regex PARSE { R"((\w+) to (\w+) = (\d+))" };
  std::unordered_map <size_t, int> dist;
  std::set <size_t> p;
  for (const auto & line : io::by_line (ifs)) {
    std::smatch m { io::regex_parse (line, PARSE) };
    size_t h1 { util::hash (m.str (1)) }, h2 { util::hash (m.str (2)) };
    p.insert (h1), p.insert (h2), dist [h1 ^ h2] = std::stoi (m.str (3));
  }

  std::vector <size_t> order { std::begin (p), std::end (p) };
  int d { part2 ? 0 : std::numeric_limits <int>::max() };
  FnType f { part2 ? (FnType)std::max <int> : (FnType)std::min <int> };
  do {
    auto prev = std::begin (order);
    d = f (d, std::accumulate (prev + 1, std::end (order), 0, [&] (int sum, size_t a) {
      return sum + dist [a ^ *(prev++)];
    }));
  } while (std::next_permutation (std::begin (order), std::end (order)));
  std::cout << d << std::endl;
}
