#include <vector>
#include "Solution.hpp"
#include "io.hpp"


template <> void solve <Day10> (bool part2, std::istream & is, std::ostream & os) {
  const int MAX_SIZE = (part2 ? 5712667 : 403154);
  std::vector <char> s (MAX_SIZE), o (MAX_SIZE);
  int count { 0 }, l;
  for (auto && c : io::by <char> (is))
    s [count++] = c - '0';
  for (int i { 0 }; i < (part2 ? 50 : 40); ++i) {
    count = 0;
    for (int c { 0 }; s[c] != 0; c += l) {
      for (l = 1; s[c + l] == s[c] && s[l] != 0; ++l)
        ;
      o[count++] = l, o[count++] = s[c];
    }
    std::swap (s, o);
  }
  os << count << std::endl;
}
