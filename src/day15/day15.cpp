#include <iostream>
#include <regex>
#include <string>
#include <valarray>
#include <vector>
#include "timer.hpp"
#include "io.hpp"

using Ingredient = std::valarray <int>;
enum Type { SUGAR = 0, SPRINKLES = 1, CANDY = 2, CHOCOLATE = 3, CALORIES = 4 };

const static std::regex PARSE { R"(\w+: capacity (-?\d+), durability (-?\d+), flavor (-?\d+), texture (-?\d+), calories (-?\d+))" };

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  std::vector <Ingredient> d;
  for (const auto & line : io::by_line { std::cin }) {
    std::smatch m { io::regex_parse (line, PARSE) };
    d.push_back ({ std::stoi (m[1]), std::stoi (m[2]), std::stoi (m[3]), std::stoi (m[4]), std::stoi (m[5]) });
  }
  uint64_t max { 0 };
  for (int u { 0 }; u <= 100; ++u)
    for (int s { 0 }; u + s <= 100; ++s)
      for (int c { 0 }; u + s + c <= 100; ++c)
        for (int o { 0 }; u + s + c + o <= 100; ++o)
          if (u + s + c + o == 100 ) {
            const auto res = (d [SUGAR]*u + d[SPRINKLES]*s + d[CANDY]*c + d[CHOCOLATE]*o);
            if (!part2 || res[CALORIES] == 500) {
              uint64_t prod = 1;
              for (int x { 0 }; x < 4; ++x)
                prod *= std::max (0, res [x]);
              max = std::max (max, prod);
            }
          }
  std::cout << max << std::endl;
  return 0;
}
