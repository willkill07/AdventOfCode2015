#include <array>
#include <regex>
#include <cstring>
#include <getopt.h>
#include "Preprocessor.hpp"
#include "Solution.hpp"
#include "timer.hpp"

struct options_t {
  bool part1 { true }, part2 { true }, time { true };
  std::regex filter { ".*" };
};

template <Day> void timeSolve (bool, bool);

void run (Day, bool, bool);

options_t parseArgs (int, char* []);

int main (int argc, char* argv[]) {
  options_t options = parseArgs (argc, argv);
  for (int d { Day01 }; d != TOTAL_DAYS; ++d) {
    Day day { static_cast <Day> (d) };
    if (!std::regex_search (asString (day), options.filter))
      continue;
    std::cout << asString (day) << ((options.part1 && options.part2) ? "\n" : ": ");
    if (options.part1) {
      if (options.part2)
        std::cout << "Part 1: ";
      run (day, false, options.time);
    }
    if (options.part2) {
      if (options.part1)
        std::cout << "Part 2: ";
      run (day, true, options.time);
    }
  }
  return EXIT_SUCCESS;
}

template <Day DAY> void timeSolve (bool part2, bool time) {
  std::ifstream ifs { "./inputs/" + asString (DAY) + ".txt" };
  if (time) {
    Timer t;
    solve <DAY> (part2, ifs);
    printf ("  time: %0.4lfms\n", t.current());
  } else
    solve <DAY> (part2, ifs);
}

#define LINK_DAY(X) extern template void solve <Day ## X> (bool, std::istream &);
EVAL(MAP(LINK_DAY,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25))
#undef LINK_DAY

#define RUN_DAY(X) case Day ## X : timeSolve <Day ## X> (part2, time); break;
void run (Day day, bool part2, bool time) {
  switch (day) {
    EVAL(MAP(RUN_DAY,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25))
    default: break;
  }
}
#undef RUN_DAY

options_t parseArgs (int argc, char* argv[]) {
  options_t options;
  static char const * const shortOpts { "htnp:f:" };
  static const std::array <const ::option, 6> longOpts {{
    { "help",    no_argument,       nullptr, 'h' },
    { "part",    required_argument, nullptr, 'p' },
    { "filter",  required_argument, nullptr, 'f' },
    { "time",    no_argument,       nullptr, 't' },
    { "no-time", no_argument,       nullptr, 'n' },
    { nullptr,   0,                 nullptr,  0  }
  }};
  int option { 0 };
  while (option = getopt_long (argc, argv, shortOpts, longOpts.data(), nullptr), option != -1) {
    switch (option) {
    case 'h':
    case '?':
      printf ("Advent of Code - 2015\n"
              "---------------------\n"
              " -h|--help )\n    print help\n"
              " -p|--part=[1,2,all] )\n    only run parts specified [default = all]\n"
              " -f|--filter=<regex> )\n    filter day on regular expression [default = match all]\n"
              " -n|--no-time )\n do not print timing of execution\n"
              " -t|--time )\n print timing of exection [default]\n"
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
    case 't':
    case 'n':
      options.time = (option == 't');
      break;
    }
  }
  return options;
}
