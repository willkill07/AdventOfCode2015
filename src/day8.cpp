#include <string>
#include <iostream>
#include "timer.hpp"

int
main (int argc, char* argv[]) {
  Timer t;
  bool part2 { argc == 2 };
  int count { 0 };
  int skip { 0 };
  char prev { '\0' };
  std::string s;
  while (std::cin >> s) {
    count += 2;
    if (!part2) {
      std::for_each (std::begin (s), std::end (s),
        [&] (char curr) {
          if (skip-- <= 0) {
            skip = 0;
            if (prev == '\\') {
              ++count;
              ++skip;
              if (curr != '\\' && curr != '\"') {
                count += 2;
                skip += 2;
              }
            }
          }
          prev = curr;
        });
    } else {
      std::for_each (std::begin (s), std::end (s),
        [&] (char curr) {
          if (curr == '"' || curr == '\\')
            ++count;
        });
    }
  }
  std::cout << count << std::endl;
  return 0;
}
