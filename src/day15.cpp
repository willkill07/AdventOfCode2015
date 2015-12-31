#include <numeric>
#include <valarray>
#include <vector>
#include "Solution.hpp"
#include "io.hpp"

const int FEATURES = 4;
const int TOTAL_TABLESPOONS = 100;

struct Ingredient {
  std::valarray <int> data; int calories;
  explicit Ingredient () : data (FEATURES), calories { 0 } { }
  Ingredient (const std::valarray <int> & d, int c) : data { d }, calories { c } { }
};

void comb (int r, int n, int* dest, std::function<void()> doNext) {
  if (r == 1)
    *dest = n, doNext ();
  else
    for (int i { 0 }; i <= n; ++i)
      *dest = i, comb (r - 1, n - i, dest + 1, doNext);
}

void for_all (int r, int n, std::function <void (int*)> f) {
  int dest [FEATURES];
  comb (r, n, dest, [&] {
    f (dest);
  });
}

Day15::Day15 () : Solution { "day15" } { }

void Day15::solve (bool part2) {
	const static std::regex PARSE { R"(\w+: capacity (-?\d+), durability (-?\d+), flavor (-?\d+), texture (-?\d+), calories (-?\d+))" };
  int count { 0 }, max { 0 };
  std::vector <Ingredient> ingredients;
  for (const auto & line : io::by_line { ifs }) {
    std::smatch m { io::regex_parse (line, PARSE) };
    ingredients.emplace_back (std::valarray <int> { std::stoi (m[1]), std::stoi (m[2]), std::stoi (m[3]), std::stoi (m[4]) }, std::stoi (m[5]));
    ++count;
  }
  for_all (count, TOTAL_TABLESPOONS, [&] (int* counts) {
    Ingredient res;
    for (int i { 0 }; i < count; ++i)
      res.data += counts[i] * ingredients[i].data, res.calories += counts[i] * ingredients[i].calories;
    if (!part2 || res.calories == 500)
      max = std::max (max, std::accumulate (std::begin (res.data), std::end (res.data), 1, [] (int p, int v) { return p * std::max (v, 0); }));
  });
  std::cout << max << std::endl;
}
