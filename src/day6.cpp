#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <regex>
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
  std::smatch fields;
  std::regex_search (line, fields, parser);

  Action a;
  if (fields [1].compare ("toggle") == 0) {
    a = TOGGLE;
  } else {
    if (std::string { fields [1] }.find ("on") != std::string::npos) {
      a = ON;
    } else {
      a = OFF;
    }
  }

  int x1 { std::stoi (fields [2]) }, y1 { std::stoi (fields [3]) },
      x2 { std::stoi (fields [4]) }, y2 { std::stoi (fields [5]) };

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

  unsigned int threadCount { std::thread::hardware_concurrency() };
  auto task = [&] (unsigned threadID) {
    int count { 0 };
    for (unsigned int x { threadID }; x < 1000; x += threadCount) {
      for (unsigned int y { 0 }; y < 1000; ++y) {
        int light { 0 };
        for (auto && r : rules) {
          r (light, x, y);
        }
        count += light;
      }
    }
    return count;
  };

  std::vector <std::future <int> > threads;
  for (int tID { 0 }; tID < threadCount; ++tID) {
    threads.push_back (std::async (task, tID));
  }
  int totalCount { 0 };
  for (auto && futureVal : threads) {
    totalCount += futureVal.get();
  }

  std::cout << totalCount << std::endl;
  return 0;
}
