#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <sstream>
#include "timer.hpp"

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  std::string s;
  std::cin >> s;
  for (int i { 0 }; i < (part2 ? 50 : 40); ++i) {
    std::ostringstream o;
    for (auto c = std::begin (s); c != std::end (s); ) {
      auto loc = std::find_if (c, std::end (s), std::bind (std::not_equal_to <char> { }, *c, std::placeholders::_1));
      o << (loc - c) << *c;
      c = loc;
    }
    s = o.str();
  }
  std::cout << s.size() << std::endl;
  return 0;
}
