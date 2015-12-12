#include <iostream>
#include <map>
#include <tuple>
#include "timer.hpp"
#include "io.hpp"

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
  bool part2 { argc == 2 };
  std::map <Pos, int> p;
  Pos p1 { 0, 0 }, p2 { 0, 0 };
  bool santa { true };
  for (char c : io::as_string (std::cin)) {
    ++p [apply (((santa ^= part2) ? p1 : p2), c)];
  }
  std::cout << p.size() << std::endl;
  return 0;
}
