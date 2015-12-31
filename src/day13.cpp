#include <limits>
#include <numeric>
#include <set>
#include <unordered_map>
#include <vector>
#include "Solution.hpp"
#include "io.hpp"
#include "util.hpp"

Day13::Day13 () : Solution { "day13" } { }

void Day13::solve (bool part2) {
  static const std::regex PARSE { R"((\w+) would (gain|lose) (\d+) happiness units by sitting next to (\w+).)" };
  std::unordered_map <size_t, int> dist;
  std::set <size_t> p;
  for (const auto & line : io::by_line (ifs)) {
    std::smatch m { io::regex_parse (line, PARSE) };
    size_t h1 { util::hash (m.str (1)) }, h2 { util::hash (m.str (4)) };
    int val { ((m.str (2) == "gain") ? 1 : -1) * std::stoi (m.str (3)) };
    p.insert (h1), p.insert (h2), dist [h1 ^ h2] += val;
  }
  std::vector <size_t> order { std::begin (p), std::end (p) };
  int d { std::numeric_limits <int>::min() };
  do {
    auto prev = std::begin (order);
    int init { part2 ? 0 : dist [(*prev) ^ (*--std::end (order))] };
    d = std::max <int> (d, std::accumulate (prev + 1, std::end (order), init, [&] (int sum, size_t a) {
      return sum + dist [a ^ *(prev++)];
    }));
  } while (std::next_permutation (std::begin (order), std::end (order)));
  std::cout << d << std::endl;
}
