#include <array>
#include <climits>
#include "Solution.hpp"
#include "io.hpp"

bool isvowel (char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool nice (const std::string & str) {
  bool pair { false };
  auto c = std::begin (str);
  int vowels { isvowel (*c) };
  for (++c; c != std::end (str); ++c) {
    if ((*c == 'b' || *c == 'd' || *c == 'q' || *c == 'y') && (*(c - 1) == *c - 1))
      return false;
    vowels += isvowel (*c);
    pair |= (*(c-1) == *c);
  }
  return pair && (vowels > 2);
}

int nicer (const std::string & str) {
  bool pair { false }, post { false };
  static std::array <std::array <char, 26>, 26> lookup;
  for (auto && l: lookup)
    l.fill (std::numeric_limits <char>::max ());
  lookup [str[0] - 'a'][str[1] - 'a'] = 1;
  char i { 2 };
  for (auto c = std::begin (str) + 2; c != std::end (str); ++c, ++i) {
    char& index = lookup [*(c - 1) - 'a'][*c - 'a'];
    if (post |= (*c == *(c - 2)), pair |= (index < i - 1), pair && post)
      return true;
    index = std::min (index, i);
  }
  return pair && post;
}

void Day05::solve (bool part2, std::ifstream & ifs) {
  static const std::regex PAIR { "R((..).*\1)" }, POST { R"((.).\1)" };
  int niceCount { 0 };
  for (auto && line : io::by <io::line> (ifs))
    niceCount += (!part2 ? nice (line) : nicer (line));
  std::cout << niceCount << std::endl;
}
