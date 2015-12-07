CC := clang++
CXX := clang++
CPPFLAGS := -Iutil/include
CXXFLAGS := -O3 -march=native -std=c++14 -Wall -pedantic
vpath day%.cpp src

.PHONY : clean distclean all run_all help

help :
	@echo "This Makefile has two main options:"
	@echo " * Running/building a single day"
	@echo " * Running/building the entire Advent"
	@echo ""
	@echo "Single Day:"
	@echo " $ make dayN       # compiles dayN"
	@echo " $ make run_dayN   # runs dayN"
	@echo ""
	@echo "Entire Advent:"
	@echo " $ make all        # compiles all days"
	@echo " $ make run_all    # runs all days"

# Variable to store days implemented
DAYS := $(basename $(notdir $(wildcard src/day*.cpp)))

# Special rules for certain days :)
day4 : util/lib/md5.o day4.o

# Build rules
all : $(DAYS)

# Execution rules
run_all : all
	make $(addprefix run_,$(DAYS))

run_% : %
	@echo "Running $<"
	@printf "Part 1: "
	@./$< < input/$<.txt
	@printf "Part 2: "
	@./$< part2 < input/$<.txt

# Cleanup
clean :
	@-rm -v *.o util/lib/*.o

distclean : clean
	@-rm -v day*
