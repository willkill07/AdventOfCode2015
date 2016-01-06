#include <array>
#include "Solution.hpp"
#include "io.hpp"

template<> void solve <Day20> (bool part2, std::istream & ifs) {
  static std::array <int, 1000000> points;
  int sum { *io::as <int> (ifs) }, weight { part2 ? 11 : 10 };
  for (size_t elf { 1 }; elf <= points.size(); ++elf) {
    for (size_t h { elf - 1 }; h < points.size() && (part2 ? h < elf * 50 : true); h += elf)
      points [h] += elf * weight;
    if (points [elf - 1] >= sum) {
      std::cout << elf << std::endl;
      return;
    }
  }
}
