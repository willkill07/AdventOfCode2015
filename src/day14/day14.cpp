#include <algorithm>
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include "timer.hpp"
#include "io.hpp"

#define COMPARE_BY(X) [] (const auto & d1, const auto & d2) { return d1 . X < d2 . X; }

const static std::regex PARSE { R"(\w+ can fly (\d+) km/s for (\d+) seconds, but then must rest for (\d+) seconds.)" };
const int TIME { 2503 };

struct Reindeer {
  int speed { 0 }, go { 0 }, rest { 0 }, dist { 0 }, points { 0 };
  explicit Reindeer() {}
  Reindeer(int _s, int _g, int _r) : speed { _s }, go { _g }, rest { _r } { }
  void tick (int t) {
    if (t % (go + rest) < go) dist += speed;
  }
};

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  std::vector <Reindeer> deer;

  for (const auto & line : io::by_line { std::cin }) {
    std::smatch m;
    std::regex_match (line, m, PARSE);
    deer.emplace_back (std::stoi (m.str (1)), std::stoi (m.str (2)), std::stoi (m.str (3)));
  }
  for (int t { 0 }; t < TIME; ++t) {
    for (auto & d : deer)
      d.tick (t);
    if (part2) {
      std::vector <int> leaders;
      int lead { 0 };
      for (const auto & d : deer)
        if (d.dist > lead)
          leaders = { (int)(&d - &deer[0]) }, lead = d.dist;
      else if (d.dist == lead)
        leaders.push_back (&d - &deer[0]);
      for (const auto & name : leaders)
        ++deer[name].points;
    }
  }
  int winner { part2
      ? std::max_element (std::begin (deer), std::end (deer), COMPARE_BY (points))->points
      : std::max_element (std::begin (deer), std::end (deer), COMPARE_BY (dist))->dist
  };
  std::cout << winner << std::endl;
  return 0;
}
