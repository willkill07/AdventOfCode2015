#include <cstdlib>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <valarray>
#include "timer.hpp"
#include "io.hpp"

static const std::regex PARSER { R"((turn (off|on)|toggle) (\d+),(\d+) through (\d+),(\d+))" };

enum Action {
  ON = 1, OFF = -1, TOGGLE = 2
};

int main (int argc, char* argv []) {
  bool part2 { argc == 2 };
  std::valarray <int> lights (1000000);
  int v[4];
  for (const auto & line : io::by_line { std::cin }) {
    std::smatch m { io::regex_parse (line, PARSER) };
    Action a = ((m.str (1) == "toggle") ? TOGGLE : ((m.str (2) == "on") ? ON : OFF));
    auto start = m.begin();
    std::advance (start, 3);
    std::transform (start, m.end(), v, io::to_int);
    for (int y { 0 }; y < 1000; ++y)
      for (int x { 0 }; x < 1000; ++x)
        if (x >= v[0] && y >= v[1] && x <= v[2] && y <= v[3]) {
          int i { y * 1000 + x };
          lights[i] = (!part2 ? (a == ON || (a == TOGGLE && lights[i] == 0)) : std::max (lights[i] + a, 0));
        }
  }
  std::cout << lights.sum() << std::endl;
  return 0;
}
