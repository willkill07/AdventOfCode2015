#include "Solution.hpp"
#include "io.hpp"

Day05::Day05 () : Solution { "day05" } { }

void Day05::solve (bool part2) {
	static const std::regex VOW3 { "([aeiou].*){3,}" }, LET2 { "(.)\\1" }, BAD { "(ab|cd|pq|xy)" }, PAIR { "(..).*\\1" }, POST { "(.).\\1" };
  int niceCount { 0 };
  for (auto str : io::by_line { ifs }) {
    niceCount += ((!part2 && std::regex_search (str, VOW3) && std::regex_search (str, LET2) && !std::regex_search (str, BAD)) || (part2 && std::regex_search (str, PAIR) && std::regex_search (str, POST)));
  }
  std::cout << niceCount << std::endl;
}
