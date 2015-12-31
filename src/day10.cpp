#include <algorithm>
#include <iterator>
#include <vector>
#include "Solution.hpp"
#include "io.hpp"

Day10::Day10 () : Solution { "day10" } { }

void Day10::solve (bool part2) {
  std::vector <char> s;
  std::transform (io::as<char> (ifs), { }, std::back_inserter (s), [] (char c) { return c - '0'; });
  for (int i { 0 }; i < (part2 ? 50 : 40); ++i) {
    std::vector <char> o;
    for (auto c = std::begin (s); c != std::end (s); ) {
      auto l = std::find_if (c, std::end (s), [c] (char o) { return *c != o; });
      o.push_back (l - c), o.push_back (*c), c = l;
    }
    s = std::move (o);
  }
  std::cout << s.size() << std::endl;
}
