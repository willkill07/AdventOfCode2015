#include <algorithm>
#include <vector>
#include "Solution.hpp"
#include "io.hpp"
#include "util.hpp"

using Inst = std::pair <int, std::function <void()>>;
using Ptr = std::vector <Inst>::const_iterator;

template <> void solve <Day23> (bool part2, std::istream & is, std::ostream & os) {
  const static std::regex PARSE { R"((\w+) (a|b|[-+\d]+)(, ([-+\d]+))?)" };
  int a { part2 }, b { 0 };
  auto getRef = [&] (auto && s) -> int & { return (s == "a") ? a : b; };
  std::vector <Inst> ins; Ptr pc;
  std::transform (io::as <io::line> (is), { }, std::back_inserter (ins), [&] (auto && line) -> Inst {
    std::smatch m { io::regex_parse (line, PARSE) };
    int & ref = getRef (m.str(2));
    switch (util::hash (m.str(1))) {
      case "hlf"_hash: return {0, [&] { ref /= 2, ++pc; }};
      case "tpl"_hash: return {0, [&] { ref *= 3, ++pc; }};
      case "inc"_hash: return {0, [&] { ++ref, ++pc; }};
      case "jmp"_hash: return {std::stoi (m.str(2)), [&] { pc += pc->first; }};
      case "jie"_hash: return {std::stoi (m.str(4)), [&] { pc += (ref & 1) ? 1 : pc->first; }};
      case "jio"_hash: return {std::stoi (m.str(4)), [&] { pc += (ref == 1) ? pc->first : 1; }};
      default: return { };
    }
  });
  for (pc = std::begin (ins); pc != std::end (ins); pc->second())
    ;
  os << b << std::endl;
}
