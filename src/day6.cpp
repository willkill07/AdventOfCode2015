#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <vector>
#include "timer.hpp"

enum Action {
  ON = 1, OFF = -1, TOGGLE = 2
};

static const std::regex PARSER { "(turn off|turn on|toggle) (\\d+),(\\d+) through (\\d+),(\\d+)" };

using ActionRule = std::function <void (int&, int, int)>;

ActionRule buildFromLine (std::string line, bool part2) {
  std::smatch m;
  std::regex_search (line, m, PARSER);
  Action a = ((m [1].compare ("toggle") == 0) ? TOGGLE : ((m [1].str().find ("on") != std::string::npos) ? ON : OFF));
  int v[4];
  auto start = m.begin();
  std::advance (start, 2);
  std::transform (start, m.end(), v, [] (auto & s) { return std::stoi (s.str()); });
  return [a,v,part2] (int &state, int x, int y) {
    if (x >= v[0] && y >= v[1] && x <= v[2] && y <= v[3])
      state = ((!part2) ? ((a == ON || (a == TOGGLE && state == 0)) ? 1 : 0) : std::max (state + a, 0));
  };
}

int main (int argc, char* argv []) {
  Timer t;
  bool part2 { argc == 2 };

  std::vector <ActionRule> rules;
  std::string input;
  while (std::getline (std::cin, input))
    rules.push_back (buildFromLine (input, part2));

  unsigned int threadCount { std::thread::hardware_concurrency() };
  auto task = [&] (unsigned threadID) {
    int count { 0 };
    for (unsigned int x { threadID }; x < 1000; x += threadCount) {
      for (unsigned int y { 0 }; y < 1000; ++y) {
        int light { 0 };
        for (auto && r : rules)
          r (light, x, y);
        count += light;
      }
    }
    return count;
  };

  std::vector <std::future <int> > threads;
  for (int tID { 0 }; tID < threadCount; ++tID)
    threads.push_back (std::async (task, tID));
  int totalCount { 0 };
  for (auto && futureVal : threads)
    totalCount += futureVal.get();
  std::cout << totalCount << std::endl;
  return 0;
}
