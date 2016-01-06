#include <limits>
#include <set>
#include <unordered_map>
#include <vector>
#include "Solution.hpp"
#include "io.hpp"

using FnType = int const & (*)(int const &, int const &);

int get_id (const std::string & city) {
  static int shift = 0;
  static std::unordered_map <std::string, int> lookup;
  auto loc = lookup.find (city);
  if (loc != std::end (lookup))
    return loc->second;
  return (lookup [city] = 1 << shift++);
}

template <> void solve <Day09> (bool part2, std::istream & ifs) {
  static const std::regex PARSE { R"((\w+) to (\w+) = (\d+))" };
  std::unordered_map <int, int> dist;
  std::set <int> p;
  for (auto && line : io::by <io::line> (ifs)) {
    std::smatch m { io::regex_parse (line, PARSE) };
    int h1 { get_id (m.str (1)) }, h2 { get_id (m.str (2)) };
    p.insert (h1), p.insert (h2), dist [h1 | h2] = std::stoi (m.str (3));
  }
  std::vector <int> order { std::begin (p), std::end (p) };
  int d { part2 ? 0 : std::numeric_limits <int>::max() };
  FnType f { part2 ? (FnType)std::max <int> : (FnType)std::min <int> };
  do {
    int curr { 0 };
    for (auto c = std::begin (order) + 1; c != std::end (order); ++c)
      curr += dist [ *c | *(c - 1) ];
    d = f (d, curr);
  } while (std::next_permutation (std::begin (order), std::end (order)));
  std::cout << d << std::endl;
}
