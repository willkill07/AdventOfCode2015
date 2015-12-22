#include <array>
#include <iostream>
#include "timer.hpp"
#include "io.hpp"
#define FORALL(X,Y) for (size_t Y { 1 }; Y <= N; ++Y) for (size_t X { 1 }; X <= N; ++X)

const size_t N { 100 };
const size_t SPAN { N + 2 };
using Grid = std::array <std::array <int, SPAN>, SPAN>;
static Grid grid[2], temp;

int sum (const Grid & a) {
  int s { 0 }; FORALL(x,y) s += a[y][x]; return s;
}

int main (int argc, char* argv[]) {
  bool part2 { argc == 2};
  size_t curr { 1 }, prev { 0 };
  {
    size_t x { 0 }, y { 0 };
    for (const auto & line : io::by_line { std::cin }) {
      x = 0, ++y;
      for (char c : line)
        grid[curr][y][++x] = ((c == '#') ? 1 : 0);
    }
    part2 && (grid[curr][1][1] = grid[curr][1][N] = grid[curr][N][1] = grid[curr][N][N] = 1);
  }
  for (size_t i { 0 }; i < 100; ++i) {
    std::swap (curr, prev);
    for (auto & row : temp)
      row.fill (0);
    FORALL(x,y) temp[y][x] += grid[prev][y][x-1] + grid[prev][y][x] + grid[prev][y][x+1];
    FORALL(x,y) grid[curr][y][x] = temp[y-1][x] + temp[y][x] + temp[y+1][x] - grid[prev][y][x];
    FORALL(x,y) grid[curr][y][x] = (grid[curr][y][x] == 3 || (grid[prev][y][x] && grid[curr][y][x] == 2));
    part2 && (grid[curr][1][1] = grid[curr][1][N] = grid[curr][N][1] = grid[curr][N][N] = 1);
  }
  std::cout << sum (grid[curr]) << std::endl;
  return 0;
}
