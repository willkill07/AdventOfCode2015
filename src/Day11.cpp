#include "Solution.hpp"
#include "io.hpp"

char & next_letter (char & c) {
  return (c = (c == 'z' ? 'a' : c + 1 + (c == 'h' || c == 'n' || c == 'k')));
}

bool valid (const std::string & pw) {
  bool two { pw[0] == pw[1] }, three { false };
  char last { '\0' };
  for (auto c = std::begin (pw) + 2; c != std::end (pw); ++c) {
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

void Day11::solve (bool part2, std::ifstream & ifs) {
  std::string pw { io::as_string (ifs) };
  std::cout << next (part2 ? next (pw) : pw) << std::endl;
}
