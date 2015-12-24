CC := clang++
CXX := clang++
CPPFLAGS := -Iutil/include
CXXFLAGS := -O3 -march=native -std=c++14 -Wall -Wextra -Werror -pedantic -pedantic-errors
FILES := $(wildcard src/day*/day*.cpp)
DAYS := $(wildcard src/day*)
RULES := $(notdir $(FILES:%.cpp=%))
pathify = $(subst $(eval),:,$(wildcard $1))
vpath day%.cpp $(call pathify,$(DAYS))
vpath %.cpp util/lib

.PHONY : all runall clean

all : $(RULES)

runall : all
	make $(addprefix run_,$(RULES))

day04 : md5.cpp day04.cpp

run_% :	%
	@printf "Running $<\n  Part 1: \n    "
	@./$< part1 < src/$</input.txt
	@printf "  Part 2: \n    "
	@./$< part2 < src/$</input.txt
	@printf "\n"
clean:
	@-rm -vf $(RULES)
