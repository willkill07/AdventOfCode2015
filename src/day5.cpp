#include <iostream>
#include <string>
#include <regex>
#include "timer.hpp"

std::regex threeVowels ("([aeiou].*){3,}");
std::regex doubleLetter ("(.)\\1");
std::regex bad ("(ab|cd|pq|xy)");

std::regex pair ("(..).*\\1");
std::regex post ("(.).\\1");

bool
isNice (const std::string& str) {
  return std::regex_search (str, threeVowels) && std::regex_search (str, doubleLetter) && !std::regex_search (str, bad);
}

bool
isNice2 (const std::string& str) {
  return std::regex_search (str, pair) && std::regex_search (str, post);
}


int
main (int argc, char* argv []) {
	Timer t;
  bool part2 { argc == 2 };
  int niceCount { 0 };

  std::string input;
  while (std::getline (std::cin, input)) {
    if ((!part2 && isNice (input)) || (part2 && isNice2 (input))) {
      ++niceCount;
    }
  }
  std::cout << niceCount << std::endl;
  return 0;
}
