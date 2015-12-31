#include <limits>
#include <set>
#include <unordered_map>
#include <vector>
#include "Solution.hpp"
#include "io.hpp"

int lookup_id (const std::string & city) {
  static int shift = 0;
  static std::unordered_map <std::string, int> lookup;
  auto loc = lookup.find (city);
  if (loc != std::end (lookup))
    return loc->second;
  return (lookup [city] = 1 << shift++);
}

void Day13::solve (bool part2, std::ifstream & ifs) {
  static const std::regex PARSE { R"((\w+) would (gain|lose) (\d+) happiness units by sitting next to (\w+).)" };
  std::unordered_map <int, int> dist;
  std::set <int> p;
  for (auto && line : io::by <io::line> (ifs)) {
    std::smatch m { io::regex_parse (line, PARSE) };
    int h1 { lookup_id (m.str (1)) }, h2 { lookup_id (m.str (4)) };
    int val { ((m.str (2) == "gain") ? 1 : -1) * std::stoi (m.str (3)) };
    p.insert (h1), p.insert (h2), dist [h1 ^ h2] += val;
  }
  std::vector <int> order { std::begin (p), std::end (p) };
  int d { std::numeric_limits <int>::min() };
  do {
    int curr { part2 ? 0 : dist [order[0] | order.back()] };
    for (auto p = std::begin (order) + 1; p != std::end (order); ++p)
      curr += dist [*p | *(p - 1)];
    d = std::max (d, curr);
  } while (std::next_permutation (std::begin (order), std::end (order)));
  std::cout << d << std::endl;
}
