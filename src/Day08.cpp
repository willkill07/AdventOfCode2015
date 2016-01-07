#include "Solution.hpp"
#include "io.hpp"

static const std::regex REDUCE { R"(\\(\\|\"|x[0-9a-f]{2}))" }, EXPAND { R"(\"|\\)" };

template <> void solve <Day08> (bool part2, std::istream & is, std::ostream & os) {
  int sum { 0 };
  if (!part2)
    for (auto && s : io::by <std::string> (is)) {
      sum += 2;
      for (auto && m : io::by_match (s, REDUCE))
        sum += m.length() - 1;
    }
  else
    for (auto && s : io::by <std::string> (is))
      sum += 2 + std::distance (io::re_search (s, EXPAND), { });
  os << sum << std::endl;
}
