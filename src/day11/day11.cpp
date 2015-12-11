#include <iostream>
#include <string>
#include "timer.hpp"
#include "io.hpp"

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
    pp = p;
    p = c;
  }
  return two && three;
}

std::string& next (std::string & pw) {
  do {
    for (char & c : io::reverser <std::string> (pw))
      if (next_letter (c) != 'a')
        break;
  } while (!valid (pw));
  return pw;
}

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  std::string pw { io::as_string (std::cin) };
  std::cout << next (part2 ? next (pw) : pw) << std::endl;
  return 0;
}
