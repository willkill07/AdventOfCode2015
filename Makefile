CC := clang++
CXX := clang++
CPPFLAGS := -Iutil/include
CXXFLAGS := -O3 -march=native -std=c++14 -Wall -pedantic

# Variable to store days implemented
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

day4 : md5.cpp day4.cpp

run_% :	%
	@echo "Running $<"
	@printf "Part 1: "
	@./$< < src/$</input.txt
	@printf "Part 2: "
	@./$< part2 < src/$</input.txt

clean:
	@-rm -vf $(RULES)
