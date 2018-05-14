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

template <> void solve <Day15> (bool part2, std::istream & is, std::ostream & os) {
  const static std::regex PARSE { R"(\w+: \w+ (-?\d+), \w+ (-?\d+), \w+ (-?\d+), \w+ (-?\d+), \w+ (-?\d+))" };
  int count { 0 }, max { 0 };
  std::vector <Ingredient> ingredients;
  for (auto && line : io::by <io::line> (is)) {
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
  os << max << std::endl;
}
