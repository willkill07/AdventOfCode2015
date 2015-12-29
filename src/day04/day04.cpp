#include <iostream>
#include <string>
#include "md5.hpp"
#include "timer.hpp"
#include "io.hpp"

int countZeros (const md5sum_t & sum) {
  return __builtin_ctz (((sum[0] & 0xF0F0F0F0) >> 4) | ((sum[0] & 0x0F0F0F0F) << 4)) >> 2;
}

int main (int argc, char* argv []) {
  bool part2 { argc == 2 && strncmp (argv[1], "part2", 5) == 0 };
  std::string input { io::as_string (std::cin) };
  int index { 0 }, off { 0 }, length { (int)input.size() };
  input.resize (192);
  while ((part2 && off < 6) || (!part2 && off < 5))
    off = countZeros (md5 ((uint8_t*)&input[0], length + sprintf (&input[0] + length, "%d", ++index)));
  std::cout << index << std::endl;
  return 0;
}
