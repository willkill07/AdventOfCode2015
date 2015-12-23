#include <iostream>
#include <regex>
#include <vector>
#include "timer.hpp"
#include "io.hpp"

constexpr uint64_t h (const char* str) {
  uint64_t ret { 0xCBF29CE484222325ull };
  while(*str) ret ^= *(str++), ret *= 0x100000001B3ull;
  return ret;
}
constexpr uint64_t operator "" _h (const char* p, size_t) {
  return h (p);
}

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  int a { part2 }, b { 0 };
  auto getRef = [&] (const std::string & s) -> int & { if (s == "a") return a; return b; };
  using Inst = std::pair <int, std::function <void()>>;
  std::vector <Inst> ins;
  std::vector <Inst>::iterator pc;
  const std::regex PARSE { R"((\w+) (a|b|[-+\d]+)(, ([-+\d]+))?)" };
  for (const auto & line : io::by_line { std::cin }) {
    std::smatch m { io::regex_parse (line, PARSE) };
    int & ref = getRef (m.str(2));
    switch (h (m.str(1).c_str())) {
      case "hlf"_h: ins.emplace_back (0, [&] { ref /= 2, ++pc; }); break;
      case "tpl"_h: ins.emplace_back (0, [&] { ref *= 3, ++pc; }); break;
      case "inc"_h: ins.emplace_back (0, [&] { ref += 1, ++pc; }); break;
      case "jmp"_h: ins.emplace_back (std::stoi (m.str(2)), [&] { pc += pc->first; }); break;
      case "jie"_h: ins.emplace_back (std::stoi (m.str(4)), [&] { pc += (ref & 1) ? 1 : pc->first; }); break;
      case "jio"_h: ins.emplace_back (std::stoi (m.str(4)), [&] { pc += (ref == 1) ? pc->first : 1; }); break;
    }
  }
  for (pc = std::begin (ins); pc != std::end (ins); pc->second())
    ; std::cout << b << std::endl;
  return 0;
}
