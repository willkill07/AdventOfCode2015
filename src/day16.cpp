#include <functional>
#include <numeric>
#include <unordered_map>
#include "Solution.hpp"
#include "io.hpp"
#include "util.hpp"

Day16::Day16 () : Solution { "day16" } { }

using FnType = std::function <bool (int, int)>;
using MapType = std::unordered_map <uint64_t, std::pair <int, FnType>>;

const static FnType EQ {std::equal_to <int>{}}, GT {std::greater <int>{}}, LT {std::less <int>{}};
const static MapType MAP {{{"children"_hash,{3,EQ}}, {"cats"_hash,{7,GT}}, {"samoyeds"_hash,{2,EQ}}, {"pomeranians"_hash,{3,LT}}, {"akitas"_hash,{0,EQ}}, {"vizslas"_hash,{0,EQ}}, {"goldfish"_hash,{5,LT}}, {"trees"_hash,{3,GT}}, {"cars"_hash,{2,EQ}}, {"perfumes"_hash,{1,EQ}}}};
const static std::regex ITEM { R"(([a-z]+): (\d))" }, NUMBER { R"((\d+))" };

bool check (const std::string & key, int val, bool part2) {
  const auto & data = MAP.at (util::hash (key));
  return (part2 ? data.second : EQ) (val, data.first);
}

void Day16::solve (bool part2) {
  for (const std::string & line : io::by_line { ifs })
    if (std::accumulate (io::re_search (line, ITEM), { }, true, [&] (bool v, const auto &m) { return v && check (m.str (1), std::stoi (m.str (2)), part2); })) {
      std::cout << io::re_search (line, NUMBER)->str (1) << std::endl;
      return;
    }
}