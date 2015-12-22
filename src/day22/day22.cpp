#include <iostream>
#include <limits>
#include <regex>
#include <string>
#include "io.hpp"
#include "timer.hpp"

class Game {
  int c { 0 };
  struct { int hp { 0 }, d { 0 }; } b;
  struct { int hp { 50 }, mana { 500 }, a { 0 }; } p;
  struct { char s { 0 }, p { 0 }, r { 0 }; } t;
public:
  Game (int hp, int d) : b { hp, d } { }
  bool effects (int & best) {
    p.mana += 101 * (--t.r >= 0);
    b.hp -= 3 * (--t.p >= 0);
    p.a = ((--t.s >= 0) ? 7 : 0);
    if (b.hp <= 0) return best = std::min (best, c), true;
    return false;
  }
  bool playerTurn (int spell, int best) {
    const static int COST [5] = {53, 73, 113, 173, 229};
    if (p.mana < COST [spell] || c + COST [spell] > best) return true;
    p.mana -= COST [spell], c += COST [spell];
    switch (spell) {
      case 0: b.hp -= 4; break;
      case 1: b.hp -= 2, p.hp += 2; break;
      case 2: if (t.s <= 0) t.s = 6; else return true; break;
      case 3: if (t.p <= 0) t.p = 6; else return true; break;
      case 4: if (t.r <= 0) t.r = 5; else return true; break;
    }
    return false;
  }
  bool bossTurn () { return (p.hp -= std::max (1, b.d - p.a)) <= 0; }
  bool hardMode (bool part2) { return ((p.hp -= (part2)) <= 0); }
};

void round (bool part2, Game g, int spell, int & best) {
  if (g.playerTurn (spell, best) || g.effects (best) || g.hardMode (part2) || g.effects (best) || g.bossTurn()) return;
  for (int i { 0 }; i < 5; ++i)
    round (part2, g, i, best);
}

int main (int argc, char* argv[]) {
  bool part2 { argc == 2};
  std::smatch m;
  int best { std::numeric_limits <int>::max() };
  std::string input { io::as_string (std::cin) };
  std::regex_search (input, m, std::regex { R"([^\d]+(\d+)[^\d]+(\d+))" } );
  Game g { std::stoi (m.str (1)), std::stoi (m.str (2)) };
  for (int i { 0 }; i < 5; ++i)
    round (part2, g, i, best);
  std::cout << best << std::endl;
  return 0;
}
