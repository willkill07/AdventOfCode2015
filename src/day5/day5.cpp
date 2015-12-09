#include <iostream>
#include <string>
#include <regex>
#include "timer.hpp"

static const std::regex VOW3 { "([aeiou].*){3,}" }, LET2 { "(.)\\1" }, BAD { "(ab|cd|pq|xy)" }, PAIR { "(..).*\\1" }, POST { "(.).\\1" };

int
main (int argc, char* argv []) {
  Timer t;
  bool part2 { argc == 2 };
  int niceCount { 0 };
  std::string str;
  while (std::getline (std::cin, str)) {
    if ((!part2 && std::regex_search (str, VOW3) && std::regex_search (str, LET2) && !std::regex_search (str, BAD)) ||
        (part2 && std::regex_search (str, PAIR) && std::regex_search (str, POST)))
      ++niceCount;
  }
  std::cout << niceCount << std::endl;
  return 0;
}
