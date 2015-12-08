#include <iostream>
#include <string>
#include <regex>
#include "timer.hpp"

const static std::regex threeVowels { "([aeiou].*){3,}" };
const static std::regex doubleLetter { "(.)\\1" };
const static std::regex bad { "(ab|cd|pq|xy)" };
const static std::regex pair { "(..).*\\1" };
const static std::regex post { "(.).\\1" };

int
main (int argc, char* argv []) {
  Timer t;
  bool part2 { argc == 2 };
  int niceCount { 0 };

  std::string str;
  while (std::getline (std::cin, str)) {
    if ((!part2 && std::regex_search (str, threeVowels) && std::regex_search (str, doubleLetter) && !std::regex_search (str, bad)) ||
        (part2 && std::regex_search (str, pair) && std::regex_search (str, post))) {
      ++niceCount;
    }
  }
  std::cout << niceCount << std::endl;
  return 0;
}
