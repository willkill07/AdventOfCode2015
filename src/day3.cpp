#include <iostream>
#include <map>
#include <tuple>
#include "timer.hpp"

using position = std::tuple <int, int>;

void updatePosition (position& p, char c) {
  switch (c) {
    case '<': --std::get<1> (p); break;
    case '>': ++std::get<1> (p); break;
    case 'v': --std::get<0> (p); break;
    case '^': ++std::get<0> (p); break;
  }
}

int main (int argc, char* argv[]) {
  Timer t;
  bool part2 { argc == 2 };

  std::map <position,  int> places;
  if (!part2) {
    char input;
    position p { 0, 0 };
    while (std::cin >> input) {
      updatePosition (p, input);
      ++places[p];
    }
  } else {
    char input;
    position p1 { 0, 0 }, p2 { 0, 0 };
    bool first { true };
    while (std::cin >> input) {
      if (first) {
        updatePosition (p1, input);
        ++places[p1];
      } else {
        updatePosition (p2, input);
        ++places[p2];
      }
      first = !first;
    }
  }

  std::cout << places.size() << std::endl;
  return 0;
}
