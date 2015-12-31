#include "Solution.hpp"
#include "io.hpp"

static const std::regex REDUCE { R"(\\(\\|\"|x[0-9a-f]{2}))" }, EXPAND { R"(\"|\\)" };

void Day08::solve (bool part2, std::ifstream & ifs) {
  int sum { 0 };
  if (!part2)
    for (auto && s : io::by <std::string> (ifs)) {
      sum += 2;
      for (auto && m : io::by_match (s, REDUCE))
        sum += m.length() - 1;
    }
  else
    for (auto && s : io::by <std::string> (ifs))
      sum += 2 + std::distance (io::re_search (s, EXPAND), { });
  std::cout << sum << std::endl;
}
