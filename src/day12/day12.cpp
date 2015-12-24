#include <iostream>
#include <stack>
#include <string>
#include "timer.hpp"
#include "io.hpp"

int main (int argc, char* argv[]) {
  bool part2 { argc == 2 && strncmp (argv[1], "part2", 5) == 0 }, minus { false };
  int sum { 0 }, value { 0 };
  std::stack <int> data;
  std::string input { io::as_string (std::cin) };
  for (size_t i { 0 }; i < input.size(); ++i) {
    char c { input [i] };
    switch (c) {
      case '{':
        data.push (sum); sum = 0; break;
      case '}':
        sum += data.top(); data.pop(); break;
      case ':':
        if (part2 && !input.compare (i, 6, ":\"red\""))
          for (sum = 0, value = 1; value > 0; ++i)
            value += ((input [i + 2] == '}') ? -1 : ((input [i + 2] == '{') ? 1 : 0));
        break;
      case '-':
        minus = true; break;
      default:
        if (c >= '0' && c <= '9') {
          for (value = (c - '0'); input [i + 1] >= '0' && input [i + 1] <= '9'; ++i)
            value = value * 10 + (input [i + 1] - '0');
          sum = (minus ? sum - value : sum + value );
        }
        minus = false;
    }
  }
  std::cout << sum << std::endl;
  return 0;
}
