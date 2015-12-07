#include <functional>
#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

enum
Action {
  ON = 1, OFF = -1, TOGGLE = 2
};

using ActionRule = std::function <void (int&, int, int)>;

std::regex parser { "(turn off|turn on|toggle) (\\d+),(\\d+) through (\\d+),(\\d+)" };
std::string replace { "$1 $2 $3 $4 $5" };

ActionRule
buildFromLine (std::string line, bool part2) {
  std::istringstream iss { std::regex_replace (line, parser, replace) };

  std::string str;
  iss >> str;

  Action a;
  if (str.compare ("toggle") == 0) {
    a = TOGGLE;
  } else {
    iss >> str;
    if (str.compare ("on") == 0) {
      a = ON;
    } else {
      a = OFF;
    }
  }

  int x1,y1,x2,y2;
  iss >> x1 >> y1 >> x2 >> y2;

  if (!part2) {
    return [a,x1,y1,x2,y2] (int &state, int x, int y) {
      if (x >= x1 && y >= y1 && x <= x2 && y <= y2)
        state = ((a == ON || (a == TOGGLE && state == 0)) ? 1 : 0);
     };
  } else {
    return [a,x1,y1,x2,y2] (int &state, int x, int y) {
      if (x >= x1 && y >= y1 && x <= x2 && y <= y2)
        state = std::max (state + a, 0);
     };
  }
}

int
main (int argc, char* argv []) {
  bool part2 { argc == 2 };

  std::vector <std::string> lines;
  std::string input;
  while (std::getline (std::cin, input)) {
    lines.push_back (input);
  }

  std::vector <ActionRule> rules;
  std::transform (std::begin (lines), std::end (lines),
                  std::back_inserter (rules),
                  [part2] (auto x) {
                    return buildFromLine (x, part2);
                  });

  int count { 0 };

  for (int x { 0 }; x < 1000; ++x) {
    for (int y { 0 }; y < 1000; ++y) {
      int light { 0 };
      for (auto r : rules) {
        r (light, x, y);
      }
      count += light;
    }
  }

  std::cout << count << std::endl;
  return 0;
}
