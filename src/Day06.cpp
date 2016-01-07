#include <array>
#include "Solution.hpp"
#include "io.hpp"

enum Action {
  ON = 1, OFF = -1, TOGGLE = 2
};

template <> void solve <Day06> (bool part2, std::istream & is, std::ostream & os) {
  static const std::regex PARSER { R"((turn (on|off)|toggle) (\d+),(\d+) \w+ (\d+),(\d+))" };
  static std::array <std::array <int, 1000>, 1000> lights;
  for (auto && line : io::by <io::line> (is)) {
    std::smatch m { io::regex_parse (line, PARSER) };
    Action a = ((m.str (1) == "toggle") ? TOGGLE : ((m.str (2) == "on") ? ON : OFF));
    int x1 { std::stoi (m[3]) }, y1 { std::stoi (m[4]) }, x2 { std::stoi (m[5]) }, y2 { std::stoi (m[6]) };
    for (int y { y1 }; y <= y2; ++y)
      for (int x { x1 }; x <= x2; ++x)
        lights [y][x] = (!part2 ? (a == ON || (a == TOGGLE && lights [y][x] == 0)) : std::max (lights [y][x] + a, 0));
  }
  int sum { 0 };
  for (auto && row : lights)
    for (auto && l : row)
      sum += l;
  os << sum << std::endl;
}
