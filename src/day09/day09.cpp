#include <iostream>
#include <limits>
#include <unordered_map>
#include <numeric>
#include <regex>
#include <set>
#include <string>
#include <vector>
#include "timer.hpp"
#include "io.hpp"

using FnType = int const & (*)(int const &, int const &);

static const std::regex PARSE { R"((\w+) to (\w+) = (\d+))" };
static std::hash <std::string> hash;

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  std::unordered_map <size_t, int> dist;
  std::set <size_t> p;
  for (const auto & line : io::by_line (std::cin)) {
    std::smatch m { io::regex_parse (line, PARSE) };
    size_t h1 { hash (m.str (1)) }, h2 { hash (m.str (2)) };
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
  return 0;
}
