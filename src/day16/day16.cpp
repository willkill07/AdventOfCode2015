#include <functional>
#include <iostream>
#include <numeric>
#include <regex>
#include <unordered_map>
#include "timer.hpp"
#include "io.hpp"

using FnType = std::function <bool (int, int)>;
using MapType = std::unordered_map <uint64_t, std::pair <int, FnType>>;

const static std::hash <std::string> hash {};
const static FnType EQ {std::equal_to <int>{}}, GT {std::greater <int>{}}, LT {std::less <int>{}};
const static MapType MAP {{{hash("children"),{3,EQ}}, {hash("cats"),{7,GT}}, {hash("samoyeds"),{2,EQ}}, {hash("pomeranians"),{3,LT}}, {hash("akitas"),{0,EQ}}, {hash("vizslas"),{0,EQ}}, {hash("goldfish"),{5,LT}}, {hash("trees"),{3,GT}}, {hash("cars"),{2,EQ}}, {hash("perfumes"),{1,EQ}}}};
const static std::regex ITEM { R"(([a-z]+): (\d))" };

bool check (const std::string & key, int val, bool part2) {
  const auto & data = MAP.at (hash (key));
  return (part2 ? data.second : EQ) (val, data.first);
}

int main (int argc, char* argv[]) {
  bool part2 { argc == 2};
  for (const std::string & line : io::by_line { std::cin }) {
    if (std::accumulate (io::re_search (line, ITEM), { }, true, [&] (bool v, const auto &m) { return v && check (m.str (1), std::stoi (m.str (2)), part2); })) {
      std::cout << line << std::endl;
      break;
    }
  }
  return 0;
}
