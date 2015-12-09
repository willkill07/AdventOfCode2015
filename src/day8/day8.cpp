#include <iostream>
#include <iterator>
#include <numeric>
#include <regex>
#include <string>
#include "timer.hpp"

static const std::regex REDUCE { R"(\\(\\|\"|x[0-9a-f]{2}))" }, EXPAND { R"(\"|\\)" };

auto fn (bool part2) -> std::function <int (int, const std::string & s)> {
  if (part2) return [] (int c, const auto &s) { return c + std::accumulate (std::sregex_iterator { s.begin(), s.end(), REDUCE }, { }, 2, [](int v, auto &m) -> int { return v + m.length() - 1; }); };
  else return [] (int c, const auto &s) { return c + 2 + std::distance (std::sregex_iterator { s.begin(), s.end(), EXPAND }, { }); };
}

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  std::cout << std::accumulate (std::istream_iterator <std::string> { std::cin }, { }, 0, fn (part2)) << std::endl;
  return 0;
}
