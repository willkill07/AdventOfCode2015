#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include "timer.hpp"

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 };
  std::string t;
  std::cin >> t;
  std::vector <char> s;
  std::transform (std::begin (t), std::end (t), std::back_inserter (s), std::bind (std::minus <char> { }, std::placeholders::_1, '0'));
  for (int i { 0 }; i < (part2 ? 50 : 40); ++i) {
    std::vector <char> o;
    for (auto c = std::begin (s); c != std::end (s); ) {
      auto l = std::find_if (c, std::end (s), std::bind (std::not_equal_to <char> { }, *c, std::placeholders::_1));
      o.push_back (l - c); o.push_back (*c);
      c = l;
    }
    s = o;
  }
  std::cout << s.size() << std::endl;
  return 0;
}
