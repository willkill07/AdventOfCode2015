#ifndef _WILLIAM_KILLIAN_SOLUTION_HPP_
#define _WILLIAM_KILLIAN_SOLUTION_HPP_

#include <fstream>
#include <iostream>
#include <string>
#include "timer.hpp"

class Solution {
  std::string name;
protected:
  Solution (std::string n) : name { n } { };
  virtual void solve (bool part2, std::ifstream & ifs) = 0;
public:
  void timeSolve (bool part2) {
    std::ifstream ifs { "./inputs/" + name + ".txt" };
    Timer t;
    this->solve (part2, ifs);
    printf ("  time: %0.4lfms\n", t.current());
  }
  std::string getDay () {
    return name;
  }
};

#define INCLUDE_DAY(X)                          \
  class X : public Solution {                   \
  public:                                       \
    X() : Solution { #X } {};                   \
  protected:                                    \
    void solve (bool, std::ifstream &);         \
  }

INCLUDE_DAY(Day01);INCLUDE_DAY(Day02);INCLUDE_DAY(Day03);
INCLUDE_DAY(Day04);INCLUDE_DAY(Day05);INCLUDE_DAY(Day06);
INCLUDE_DAY(Day07);INCLUDE_DAY(Day08);INCLUDE_DAY(Day09);
INCLUDE_DAY(Day10);INCLUDE_DAY(Day11);INCLUDE_DAY(Day12);
INCLUDE_DAY(Day13);INCLUDE_DAY(Day14);INCLUDE_DAY(Day15);
INCLUDE_DAY(Day16);INCLUDE_DAY(Day17);INCLUDE_DAY(Day18);
INCLUDE_DAY(Day19);INCLUDE_DAY(Day20);INCLUDE_DAY(Day21);
INCLUDE_DAY(Day22);INCLUDE_DAY(Day23);INCLUDE_DAY(Day24);
INCLUDE_DAY(Day25);

#endif
