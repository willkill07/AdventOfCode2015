#include <iostream>
#include <map>
#include <tuple>
#include "timer.hpp"

using position = std::tuple <int, int>;

position& updatePosition (position& p, char c) {
  switch (c) {
    case '<': --std::get<1> (p); break;
    case '>': ++std::get<1> (p); break;
    case 'v': --std::get<0> (p); break;
    case '^': ++std::get<0> (p); break;
  }
  return p;
}

int main (int argc, char* argv[]) {
  Timer t;
  bool part2 { argc == 2 };
  std::map <position,  int> places;
  if (!part2) {
    char input;
    position p { 0, 0 };
    while (std::cin >> input)
      ++places [updatePosition (p, input)];
  } else {
    char input;
    position p1 { 0, 0 }, p2 { 0, 0 };
    bool first { false };
    while (first = !first, std::cin >> input)
      if (first)
        ++places [updatePosition (p1, input)];
      else
        ++places [updatePosition (p2, input)];
  }
  std::cout << places.size() << std::endl;
  return 0;
}
