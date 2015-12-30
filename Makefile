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

.PHONY : all runall clean runpart1 runpart2

day04 : md5.cpp day04.cpp

all : $(RULES)

runall : all
	@make $(addprefix run_,$(RULES))

runpart1 : all
	@make $(addprefix part1_,$(RULES))

runpart2 : all
	@make $(addprefix part2_,$(RULES))

run_% :	%
	@make header_$< runpart1_$< runpart2_$<

part1_% : %
	@make header_$< runpart1_$<

part2_% : %
	@make header_$< runpart2_$<

header_% : %
	@/bin/echo $(shell sed 's/day/Day /' <<< $<)

runpart1_% : %
	@printf "  Part 1: "
	@./$< part1 < src/$</input.txt

runpart2_% : %
	@printf "  Part 2: "
	@./$< part2 < src/$</input.txt

clean:
	@-rm -vf $(RULES)
