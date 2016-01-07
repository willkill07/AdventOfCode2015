#include "Solution.hpp"
#include "io.hpp"

char & next_letter (char & c) {
  return (c = (c == 'z' ? 'a' : c + 1 + (c == 'h' || c == 'n' || c == 'k')));
}

bool valid (const std::string & pw) {
  bool two { pw[0] == pw[1] }, three { false };
  char last { '\0' };
  for (auto && c = std::cbegin (pw) + 2; c != std::cend (pw); ++c) {
    if (!two && (*c == *(c - 1)) && (last != *c)) {
      if (last == '\0')
        last = *c;
      else
        two = true;
    }
    three = three || ((*c - 1 == *(c - 1)) && (*c - 2 == *(c - 2)));
  }
  return two && three;
}

std::string next (std::string pw) {
  do {
    for (auto && c : io::reverser (pw))
      if (next_letter (c) != 'a')
        break;
  } while (!valid (pw));
  return pw;
}

template <> void solve <Day11> (bool part2, std::istream & is, std::ostream & os) {
  std::string pw { io::as_string (is) };
  os << next (part2 ? next (pw) : pw) << std::endl;
}
