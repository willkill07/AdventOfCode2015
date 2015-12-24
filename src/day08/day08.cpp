#include <iostream>
#include <iterator>
#include <numeric>
#include <regex>
#include <string>
#include "timer.hpp"
#include "io.hpp"

static const std::regex REDUCE { R"(\\(\\|\"|x[0-9a-f]{2}))" }, EXPAND { R"(\"|\\)" };

struct Str {
  bool second;
  Str (bool p2) : second { p2 } { }
  int operator() (int c, const std::string &s) {
    if (!second)
      return c + std::accumulate (io::re_search (s, REDUCE), { }, 2, [](int v, auto &m) -> int {
          return v + m.length() - 1;
        });
    return c + 2 + std::distance (io::re_search (s, EXPAND), { });
  }
};

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 && strncmp (argv[1], "part2", 5) == 0 };
  std::cout << std::accumulate (io::as <std::string> (std::cin), { }, 0, Str { part2 }) << std::endl;
  return 0;
}
