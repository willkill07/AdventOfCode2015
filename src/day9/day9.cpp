#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <regex>
#include <set>
#include <string>
#include <vector>
#include "timer.hpp"

using City = std::string;
using Road = std::pair <City, City>;

Road get (City a, City b) {
  return (a.compare (b) >= 0) ? Road { a, b } : Road { b, a };
}

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  std::map <Road, int> dist;
  std::set <City> p;
  City line;
  std::smatch m;
  while (std::getline (std::cin, line)) {
    std::regex_search (line, m, std::regex { R"((\w+) to (\w+) = (\d+))" });
    int val { std::stoi (m[3]) };
    p.insert (m[1]);
    p.insert (m[2]);
    dist.insert ({ get (m[1], m[2]) , val });
  }
  std::vector <City> order { std::begin (p), std::end (p) };
  auto comp = [part2] (int a, int b) { return (part2) ? std::max (a, b) : std::min (a, b); };
  int d { (part2) ? 0 : std::numeric_limits <int>::max() };
  do {
    auto prev = std::begin (order);
    d = comp (d, std::accumulate (std::begin (order) + 1, std::end (order), 0, [&] (int sum, City & a) {
      return sum + dist.at (get (a, *(prev++)));
    }));
  } while (std::next_permutation (std::begin (order), std::end (order)));
  std::cout << d << std::endl;
  return 0;
}
