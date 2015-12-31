#ifndef _WILLIAM_KILLIAN_SOLUTION_HPP_
#define _WILLIAM_KILLIAN_SOLUTION_HPP_

#include <fstream>
#include <iostream>
#include <string>

class Solution {
	std::string name;
protected:
	std::ifstream ifs;
	virtual void solve (bool part2) = 0;
public:
	Solution (std::string n);
	void timeSolve (bool part2);
	std::string getDay ();
};

class Day01 : public Solution { public: Day01(); protected: void solve (bool); };
class Day02 : public Solution { public: Day02(); protected: void solve (bool); };
class Day03 : public Solution { public: Day03(); protected: void solve (bool); };
class Day04 : public Solution { public: Day04(); protected: void solve (bool); };
class Day05 : public Solution { public: Day05(); protected: void solve (bool); };
class Day06 : public Solution { public: Day06(); protected: void solve (bool); };
class Day07 : public Solution { public: Day07(); protected: void solve (bool); };
class Day08 : public Solution { public: Day08(); protected: void solve (bool); };
class Day09 : public Solution { public: Day09(); protected: void solve (bool); };
class Day10 : public Solution { public: Day10(); protected: void solve (bool); };
class Day11 : public Solution { public: Day11(); protected: void solve (bool); };
class Day12 : public Solution { public: Day12(); protected: void solve (bool); };
class Day13 : public Solution { public: Day13(); protected: void solve (bool); };
class Day14 : public Solution { public: Day14(); protected: void solve (bool); };
class Day15 : public Solution { public: Day15(); protected: void solve (bool); };
class Day16 : public Solution { public: Day16(); protected: void solve (bool); };
class Day17 : public Solution { public: Day17(); protected: void solve (bool); };
class Day18 : public Solution { public: Day18(); protected: void solve (bool); };
class Day19 : public Solution { public: Day19(); protected: void solve (bool); };
class Day20 : public Solution { public: Day20(); protected: void solve (bool); };
class Day21 : public Solution { public: Day21(); protected: void solve (bool); };
class Day22 : public Solution { public: Day22(); protected: void solve (bool); };
class Day23 : public Solution { public: Day23(); protected: void solve (bool); };
class Day24 : public Solution { public: Day24(); protected: void solve (bool); };
class Day25 : public Solution { public: Day25(); protected: void solve (bool); };

#endif
