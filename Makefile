CC := clang++
CXX := clang++
CPPFLAGS := -Iutil/include
CXXFLAGS := -O3 -march=native -std=c++14 -Wall -pedantic

# Variable to store days implemented
DAYS := $(wildcard src/day*)
EXES := $(DAYS:src/%=%)

pathify = $(subst $(eval) ,:,$(wildcard $1))
vpath day%.cpp $(call pathify,$(DAYS))

.PHONY : all run_all clean distclean

# Build rules
all : $(EXES)

% : %/%.cpp

# Execution rules
run_all : all
	@make $(addprefix run_,$(EXES))

run_% : %
	@echo "Running $<"
	@printf "Part 1: "
	@./$< < src/$</input.txt
	@printf "Part 2: "
	@./$< part2 < src/$</input.txt

# Special rules for certain days :)
day4 : util/lib/md5.cpp day4.cpp

# Cleanup
clean :
	@-rm -v *.o util/lib/*.o

distclean : clean
	@-rm -v day*
