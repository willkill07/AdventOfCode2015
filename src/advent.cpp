#include <array>
#include <regex>
#include <cstring>
#include <getopt.h>
#include "Solution.hpp"

struct options_t {
  bool part1 { true }, part2 { true };
  std::regex filter { ".*" };
};

static const std::array <std::unique_ptr <Solution>, 25> SOLUTIONS {{
  std::make_unique <Day01> (), std::make_unique <Day02> (), std::make_unique <Day03> (),
  std::make_unique <Day04> (), std::make_unique <Day05> (), std::make_unique <Day06> (),
  std::make_unique <Day07> (), std::make_unique <Day08> (), std::make_unique <Day09> (),
  std::make_unique <Day10> (), std::make_unique <Day11> (), std::make_unique <Day12> (),
  std::make_unique <Day13> (), std::make_unique <Day14> (), std::make_unique <Day15> (),
  std::make_unique <Day16> (), std::make_unique <Day17> (), std::make_unique <Day18> (),
  std::make_unique <Day19> (), std::make_unique <Day20> (), std::make_unique <Day21> (),
  std::make_unique <Day22> (), std::make_unique <Day23> (), std::make_unique <Day24> (),
  std::make_unique <Day25> ()
}};

options_t parseArgs (int argc, char* argv[]) {
  options_t options;
  static char const * const shortOpts { "p:f:h" };
  static const std::array <const ::option, 4> longOpts {{
    { "help",   no_argument,       nullptr, 'h' },
    { "part",   required_argument, nullptr, 'p' },
    { "filter", required_argument, nullptr, 'f' },
    { nullptr,  0,                 nullptr,  0  }
  }};
  int option { 0 };
  while (option = getopt_long (argc, argv, shortOpts, longOpts.data(), nullptr), option != -1) {
    switch (option) {
    case 'h':
    case '?':
      printf ("Advent of Code - 2015\n"
              "---------------------\n"
              " -h|--help )\n    print help\n"
              " -p|--part=[1,2,all] )\n    only run parts specified\n"
              " -f|--filter=<regex> )\n    filter day on regular expression\n"
              "\n"
              " Implementation by William Killian (c) 2015-2016\n");
      exit (EXIT_SUCCESS);
      break;
    case 'p':
      if (optarg[0] == '1')
        options.part2 = false;
      else if (optarg[0] == '2')
        options.part1 = false;
      break;
    case 'f':
      options.filter = std::regex { optarg };
      break;
    }
  }
  return options;
}

int main (int argc, char* argv[]) {
  options_t options = parseArgs (argc, argv);
  for (auto && day : SOLUTIONS) {
    if (!std::regex_search (day->getDay(), options.filter))
      continue;
    std::cout << day->getDay() << '\n';
    if (options.part1) {
      std::cout << "Part 1: ";
      day->timeSolve (false);
    }
    if (options.part2) {
      std::cout << "Part 2: ";
      day->timeSolve (true);
    }
  }
  return EXIT_SUCCESS;
}
