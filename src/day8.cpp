#include <iostream>
#include <iterator>
#include <numeric>
#include <regex>
#include <string>
#include "timer.hpp"

using SI = std::sregex_iterator;

static const std::regex REDUCE { R"(\\(\\|\"|x[0-9a-f]{2}))" };
static const std::regex EXPAND { R"(\"|\\)" };

auto fn1 = [] (int c, auto &s) -> int {
  return c + std::accumulate (SI { s.begin(), s.end(), REDUCE }, { }, 2, [](int v, auto &m) -> int { return v + m.length() - 1; });
};
auto fn2 = [] (int c, auto &s) -> int {
  return c + 2 + std::distance (SI { s.begin(), s.end(), EXPAND }, { });
};

int main (int argc, char* argv[]) {
  Timer t;
  bool part2 { argc == 2 };
  if (!part2) {
    std::cout << std::accumulate (std::istream_iterator <std::string> { std::cin }, { }, 0, fn1) << std::endl;
  } else {
    std::cout << std::accumulate (std::istream_iterator <std::string> { std::cin }, { }, 0, fn2) << std::endl;
  }
  return 0;
}
