#include "Solution.hpp"
#include "timer.hpp"

Solution::Solution (std::string n) :
  name { n }, ifs {  }
{ }

void Solution::timeSolve (bool part2) {
  ifs.open ("./inputs/" + name + ".txt");
  Timer t;
  this->solve (part2);
  printf ("  time: %0.8lfs\n", t.current());
  ifs.close();
}

std::string Solution::getDay () {
  return name;
}
