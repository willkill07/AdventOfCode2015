#include <limits>
#include <unordered_set>
#include "Solution.hpp"
#include "io.hpp"

class Game {
  short c { 0 }, mana { 500 }, p_hp { 50 }, b_hp { 0 };
  char p_p { 0 }, b_p { 0 }, ts { 0 }, tp { 0 }, tr { 0 };
public:
  Game (char hp, char d) : b_hp { hp }, b_p { d } { }
  bool effects (short & best) {
    mana += 101 * (--tr >= 0), b_hp -= 3 * (--tp >= 0), p_p = ((--ts >= 0) ? 7 : 0);
    if (b_hp <= 0)
      return best = std::min (best, c), true;
    return false;
  }
  bool playerTurn (int spell, short best) {
    const static short COST [5] = {53, 73, 113, 173, 229};
    if (mana < COST [spell] || c + COST [spell] > best)
      return true;
    mana -= COST [spell], c += COST [spell];
    switch (spell) {
      case 0: b_hp -= 4; break;
      case 1: b_hp -= 2, p_hp += 2; break;
      case 2: if (ts <= 0) ts = 6; else return true; break;
      case 3: if (tp <= 0) tp = 6; else return true; break;
      case 4: if (tr <= 0) tr = 5; else return true; break;
    }
    return false;
  }
  bool bossTurn () {
    return (p_hp -= std::max (1, b_p - p_p)) <= 0;
  }
  bool hardMode (bool part2) {
    return ((p_hp -= (part2)) <= 0);
  }
};

struct GameHash {
  int64_t operator() (const Game & g1) {
    return *(int64_t*)(&g1) ^ (int64_t)*(int*)((int64_t*)&g1 + 1);
  }
};

struct GameEq {
  static GameHash h;
  bool operator() (const Game & g1, const Game & g2) {
    return h(g1) == h(g2);
  }
};

bool memoized (const Game & g) {
  static std::unordered_set <Game, GameHash, GameEq> states;
  return !states.insert (g).second;
}

void round (bool part2, Game g, int spell, short & best) {
  if (g.playerTurn (spell, best) || g.effects (best) || g.hardMode (part2) || g.effects (best) || g.bossTurn() || memoized (g))
    return;
  for (int i { 0 }; i < 5; ++i)
    round (part2, g, i, best);
}

void Day22::solve (bool part2, std::ifstream & ifs) {
  short best { std::numeric_limits <short>::max() };
  std::string line { io::as_string (ifs) };
  std::smatch m { io::regex_parse (line, std::regex { R"([^:]+: (\d+)\s+[^:]+: (\d+)\s+)" }) };
  Game g { (char)std::stoi (m.str (1)), (char)std::stoi (m.str (2)) };
  for (int i { 0 }; i < 5; ++i)
    round (part2, g, i, best);
  std::cout << best << std::endl;
}
