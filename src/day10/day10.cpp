#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "timer.hpp"
#include "io.hpp"

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 && strncmp (argv[1], "part2", 5) == 0 };
  std::vector <char> s;
  std::transform (io::as<char> (std::cin), { }, std::back_inserter (s), [] (char c) { return c - '0'; });
  for (int i { 0 }; i < (part2 ? 50 : 40); ++i) {
    std::vector <char> o;
    for (auto c = std::begin (s); c != std::end (s); ) {
      auto l = std::find_if (c, std::end (s), [c] (char o) { return *c != o; });
      o.push_back (l - c), o.push_back (*c), c = l;
    }
    s = std::move (o);
  }
  std::cout << s.size() << std::endl;
  return 0;
}
