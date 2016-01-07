#include <stack>
#include "Solution.hpp"
#include "io.hpp"

template <> void solve <Day12> (bool part2, std::istream & is, std::ostream & os) {
  bool minus { false };
  int sum { 0 }, value { 0 };
  std::stack <int> data;
  std::string input { io::as_string (is) };
  for (size_t i { 0 }; i < input.size(); ++i) {
    char c { input [i] };
    switch (c) {
    case '{':
      data.push (sum); sum = 0; break;
    case '}':
      sum += data.top(); data.pop(); break;
    case ':':
      if (part2 && !input.compare (i + 2, 4, "red\""))
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
  os << sum << std::endl;
}
