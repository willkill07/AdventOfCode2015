#include <array>
#include <climits>
#include "Solution.hpp"
#include "io.hpp"

bool isvowel (char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool nice (const std::string & str) {
  bool pair { false };
  auto && c = std::cbegin (str);
  int vowels { isvowel (*c) };
  for (++c; c != std::cend (str); ++c) {
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
  for (auto && c = std::cbegin (str) + 2; c != std::cend (str); ++c, ++i) {
    char& index = lookup [*(c - 1) - 'a'][*c - 'a'];
    if (post |= (*c == *(c - 2)), pair |= (index < i - 1), pair && post)
      return true;
    index = std::min (index, i);
  }
  return pair && post;
}

template <> void solve <Day05> (bool part2, std::istream & is, std::ostream & os) {
  static const std::regex PAIR { "R((..).*\1)" }, POST { R"((.).\1)" };
  int niceCount { 0 };
  for (auto && line : io::by <io::line> (is))
    niceCount += (!part2 ? nice (line) : nicer (line));
  os << niceCount << std::endl;
}
