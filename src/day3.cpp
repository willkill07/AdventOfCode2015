#include <iostream>
#include <map>
#include <tuple>
#include "timer.hpp"

using Pos = std::tuple <int, int>;

Pos& apply (Pos& p, char c) {
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
  std::map <Pos, int> places;
  char input;
  if (!part2) {
    Pos p { 0, 0 };
    while (std::cin >> input)
      ++places [apply (p, input)];
  } else {
    Pos p1 { 0, 0 }, p2 { 0, 0 };
    bool first { false };
    while (first = !first, std::cin >> input)
      ++places [apply ((first ? p1 : p2), input)];
  }
  std::cout << places.size() << std::endl;
  return 0;
}
