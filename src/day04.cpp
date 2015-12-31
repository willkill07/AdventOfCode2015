#include "Solution.hpp"
#include "io.hpp"
#include "md5.hpp"

Day04::Day04 () : Solution { "day04" } { }

int countZeros (const md5sum_t & sum) {
  return __builtin_ctz (((sum[0] & 0xF0F0F0F0) >> 4) | ((sum[0] & 0x0F0F0F0F) << 4)) >> 2;
}

void Day04::solve (bool part2) {
  std::string input { io::as_string (ifs) };
  int index { 0 }, off { 0 }, length { (int)input.size() };
  input.resize (192);
  while ((part2 && off < 6) || (!part2 && off < 5))
    off = countZeros (md5 ((uint8_t*)&input[0], length + sprintf (&input[0] + length, "%d", ++index)));
  std::cout << index << std::endl;
}
