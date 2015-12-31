#include <valarray>
#include "Solution.hpp"
#include "io.hpp"

Day06::Day06 () : Solution { "day06" } { }

enum Action {
  ON = 1, OFF = -1, TOGGLE = 2
};

void Day06::solve (bool part2) {
	static const std::regex PARSER { R"((turn (off|on)|toggle) (\d+),(\d+) through (\d+),(\d+))" };
	std::valarray <int> lights (1000000);
  for (const auto & line : io::by_line { ifs }) {
    std::smatch m { io::regex_parse (line, PARSER) };
    Action a = ((m.str (1) == "toggle") ? TOGGLE : ((m.str (2) == "on") ? ON : OFF));
    int x1 { std::stoi (m[3]) }, y1 { std::stoi (m[4]) }, x2 { std::stoi (m[5]) }, y2 { std::stoi (m[6]) };
    for (int y { y1 }; y <= y2; ++y)
      for (int x { x1 }; x <= x2; ++x)
        lights [x + y * 1000] = (!part2 ? (a == ON || (a == TOGGLE && lights [x + y * 1000] == 0)) : std::max (lights [x + y * 1000] + a, 0));
  }
  std::cout << lights.sum() << std::endl;
}
