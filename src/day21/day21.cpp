#include <array>
#include <cmath>
#include <iostream>
#include <regex>
#include "io.hpp"
#include "timer.hpp"

const static std::regex PARSE_FILE { R"([^\d]+(\d+)[^\d]+(\d+)[^\d]+(\d+))" };

struct Item { int c{0}, d{0}, a{0}; };
struct Player { int hp{100}, d{0}, a{0}; };
const static std::array <Item,5> WEAPONS {{{8,4,0},{10,5,0},{25,6,0},{40,7,0},{74,8,0}}};
const static std::array <Item,6> ARMOR {{{13,0,1},{31,0,2},{53,0,3},{75,0,4},{102,0,5}}};
const static std::array <Item,7> RINGS {{{25,1,0},{50,2,0},{100,3,0},{20,0,1},{40,0,2},{80,0,3}}};

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 && strncmp (argv[1], "part2", 5) == 0 };
  std::smatch m;
  std::string data { io::as_string (std::cin) };
  std::regex_search (data, m, PARSE_FILE);
  Player boss = { std::stoi (m[1]), std::stoi (m[2]), std::stoi (m[3]) };
  int minCost { 746 }, maxCost { 0 };
  for (auto w : WEAPONS)
    for (auto a : ARMOR)
      for (auto r1 : RINGS)
        for (auto r2 : RINGS)
          if (r1.c != r2.c || r1.c == 0) {
            if (boss.hp * std::max (1, boss.d - (w.a + a.a + r1.a + r2.a)) <= 100 * std::max (1, (w.d + a.d + r1.d + r2.d) - boss.a))
              minCost = std::min (minCost, w.c + a.c + r1.c + r2.c);
            else
              maxCost = std::max (maxCost, w.c + a.c + r1.c + r2.c);
          }
  std::cout << (part2 ? maxCost : minCost) << std::endl;
  return 0;
}
