#include <iostream>
#include <string>
#include "md5.hpp"
#include "timer.hpp"

int main (int argc, char* argv []) {
  Timer t;
  bool part2 { argc == 2 };
  const std::string Z { "000000" };
  std::string input;
  std::cin >> input;
  int index { 1 }, off { 0 };
  while (off = std::mismatch (std::begin (Z), std::end (Z), std::begin (md5 (input + std::to_string (index)))).first - std::begin (Z), (!part2 && off < 5) || (part2 && off < 6)) {
    ++index;
  }
  std::cout << index << std::endl;
  return 0;
}
