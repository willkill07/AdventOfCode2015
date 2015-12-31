#include "Solution.hpp"
#include "io.hpp"

Day11::Day11 () : Solution { "day11" } { }

char & next_letter (char & c) {
  return (c = (c == 'z' ? 'a' : c + 1 + (c == 'h' || c == 'n' || c == 'k')));
}

bool valid (const std::string & pw) {
  bool two { false }, three { false };
  char pp { '\0' }, p { '\0' }, l { '\0' };
  for (char c : pw) {
    if (!two && c == p && c != l) {
      if (l != '\0')
        two = true;
      else
        l = c;
    }
    three = three || (((pp + 1) == p) && ((p + 1) == c));
    pp = p, p = c;
  }
  return two && three;
}

std::string& next (std::string & pw) {
  do {
    for (char & c : io::reverser (pw))
      if (next_letter (c) != 'a')
        break;
  } while (!valid (pw));
  return pw;
}

void Day11::solve (bool part2) {
  std::string pw { io::as_string (ifs) };
  std::cout << next (part2 ? next (pw) : pw) << std::endl;
}
