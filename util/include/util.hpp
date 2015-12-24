#ifndef _WILLIAM_KILLIAN_UTIL_HPP_
#define _WILLIAM_KILLIAN_UTIL_HPP_

#include <algorithm>
#include <vector>

namespace util {

  class combination {
    bool cont { true };
    std::vector <bool> v;

  public:
    combination (size_t n, size_t r) : v (r, true) {
      v.resize (n, false);
    }

    bool next (std::vector <size_t> & res) {
      if (!cont) return false;
      for (size_t i { 0 }, j { 0 }; i < v.size(); ++i)
        if (v [i])
          res [j++] = i;
      cont = std::prev_permutation (std::begin (v), std::end (v));
      return true;
    }
  };

}

#endif
