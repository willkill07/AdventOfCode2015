#include <array>
#include "Solution.hpp"

static std::array <std::unique_ptr <Solution>, 25> SOLUTIONS {{
  std::make_unique <Day01> (),
  std::make_unique <Day02> (),
  std::make_unique <Day03> (),
  std::make_unique <Day04> (),
  std::make_unique <Day05> (),
  std::make_unique <Day06> (),
  std::make_unique <Day07> (),
  std::make_unique <Day08> (),
  std::make_unique <Day09> (),
  std::make_unique <Day10> (),
  std::make_unique <Day11> (),
  std::make_unique <Day12> (),
  std::make_unique <Day13> (),
  std::make_unique <Day14> (),
  std::make_unique <Day15> (),
  std::make_unique <Day16> (),
  std::make_unique <Day17> (),
  std::make_unique <Day18> (),
  std::make_unique <Day19> (),
  std::make_unique <Day20> (),
  std::make_unique <Day21> (),
  std::make_unique <Day22> (),
  std::make_unique <Day23> (),
  std::make_unique <Day24> (),
  std::make_unique <Day25> ()
}};

int main () {
  for (auto && day : SOLUTIONS) {
    std::cout << day->getDay() << '\n';
    std::cout << "Part 1: ";
    day->timeSolve (false);
    std::cout << std::endl;
    std::cout << "Part 2: ";
    day->timeSolve (true);
    std::cout << std::endl;
  }
  return EXIT_SUCCESS;
}
