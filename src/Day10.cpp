#include <vector>
#include "Solution.hpp"
#include "io.hpp"

void Day10::solve (bool part2, std::ifstream & ifs) {
  std::vector <char> s, o;
  for (auto && c : io::by <char> (ifs))
    s.push_back (c - '0');
  for (int i { 0 }; i < (part2 ? 50 : 40); ++i) {
    std::vector <char>::iterator c, l;
    for (c = std::begin (s); c != std::end (s); ) {
      for (l = c; *l == *c && l != std::end (s); ++l)
        ;
      o.push_back (l - c), o.push_back (*c), c = l;
    }
    std::swap (s, o);
    o.clear();
  }
  std::cout << s.size() << std::endl;
}
