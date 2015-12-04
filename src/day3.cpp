#include <tuple>
#include <set>
#include <iostream>

using position = std::tuple <int, int>;

void updatePosition (position& p, char c) {
  switch (c) {
  case '<':
    --std::get<1> (p);
    break;
  case '>':
    ++std::get<1> (p);
    break;
  case 'v':
    --std::get<0> (p);
    break;
  case '^':
    ++std::get<0> (p);
    break;
  }
}

int main (int argc, char* argv[]) {
  char input;
  position p1 { 0, 0 }, p2 { 0, 0 };
  std::set <position> places;
  bool first { true };
  bool part2 { argc == 2 };
  while (std::cin >> input) {
    if (first) {
      updatePosition (p1, input);
      places.insert (p1);
    } else {
      updatePosition (p2, input);
      places.insert (p2);
    }
    if (part2)
      first = !first;
  }
  std::cout << places.size() << std::endl;
  return 0;
}
