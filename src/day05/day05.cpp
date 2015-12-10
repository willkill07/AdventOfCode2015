#include <iostream>
#include <string>
#include <regex>
#include "timer.hpp"
#include "io.hpp"

static const std::regex VOW3 { "([aeiou].*){3,}" }, LET2 { "(.)\\1" }, BAD { "(ab|cd|pq|xy)" }, PAIR { "(..).*\\1" }, POST { "(.).\\1" };

int main (int argc, char* argv []) {
  bool part2 { argc == 2 };
  int niceCount { 0 };
  for (auto str : io::by_line { std::cin }) {
    niceCount += ((!part2 && std::regex_search (str, VOW3) && std::regex_search (str, LET2) && !std::regex_search (str, BAD)) || (part2 && std::regex_search (str, PAIR) && std::regex_search (str, POST)));
  }
  std::cout << niceCount << std::endl;
  return 0;
}
