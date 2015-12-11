#include <iostream>
#include <string>
#include <regex>
#include "timer.hpp"
#include "io.hpp"

static const std::string ALPHA { "abcdefgh pqrstuvwxyz" };

char next_letter (char & c) {
  return (c = (c == 'z' ? 'a' : c + 1 + (c == 'h' || c == 'n' || c == 'k')));
}

bool valid (std::string & pw) {
  bool doubleLetter { false }, three { false };
  char prev { '\0' }, last { '\0' };
  for (char & c : pw) {
    if (!doubleLetter && c == prev && c != last) {
      if (last != '\0')
        doubleLetter = true;
      else
        last = c;
    }
    prev = c;
    three = three || (ALPHA.find (&c, 0, 3) != std::string::npos);
  }
  return doubleLetter && three;
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
