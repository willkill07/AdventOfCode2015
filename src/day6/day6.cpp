#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <vector>
#include "timer.hpp"

using ActionRule = std::function <void (int&, int, int)>;

static const std::regex PARSER { R"((turn (off|on)|toggle) (\d+),(\d+) through (\d+),(\d+))" };

enum Action {
  ON = 1, OFF = -1, TOGGLE = 2
};

ActionRule buildFromLine (std::string line, bool part2) {
  std::smatch m;
  std::regex_search (line, m, PARSER);
  Action a = ((m[1] == "toggle") ? TOGGLE : ((m[2] == "on") ? ON : OFF));
  int v[4];
  auto start = m.begin();
  std::advance (start, 3);
  std::transform (start, m.end(), v, [] (auto s) {
      return std::stoi (s);
    });
  return [a,v,part2] (int &state, int x, int y) {
    if (x >= v[0] && y >= v[1] && x <= v[2] && y <= v[3])
      state = (!part2 ? (a == ON || (a == TOGGLE && state == 0)) : std::max (state + a, 0));
  };
}

int main (int argc, char* argv []) {
  bool part2 { argc == 2 };
  std::vector <ActionRule> rules;
  std::string input;
  while (std::getline (std::cin, input))
    rules.push_back (buildFromLine (input, part2));
  int threads { (int)std::thread::hardware_concurrency() };
  auto task = [&] (int id) {
    int count { 0 };
    for (int x { id }; x < 1000; x += threads) {
      for (int y { 0 }; y < 1000; ++y) {
        int light { 0 };
        for (auto && r : rules)
          r (light, x, y);
        count += light;
      }
    }
    return count;
  };
  std::vector <std::future <int>> tasks { (size_t)threads };
  int count { threads };
  for (auto & t : tasks)
    t = std::async (task, --count);
  for (auto & ret : tasks)
    count += ret.get();
  std::cout << count << std::endl;
  return 0;
}
