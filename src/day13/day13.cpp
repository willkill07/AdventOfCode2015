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

static const std::regex PARSE { R"((\w+) would (gain|lose) (\d+) happiness units by sitting next to (\w+).)" };
static std::hash <std::string> hash;

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  std::unordered_map <size_t, int> dist;
  std::set <size_t> p;
  for (const auto & line : io::by_line (std::cin)) {
    std::smatch m;
    std::regex_match (line, m, PARSE);
    size_t h1 { hash (m.str (1)) }, h2 { hash (m.str (4)) };
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
  return 0;
}
