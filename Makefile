CC := clang++
CXX := clang++
CPPFLAGS := -Iutil/include
CXXFLAGS := -O3 -march=native -std=c++14
vpath day%.cpp src

.PHONY : clean distclean all run_all help

help :
	@echo "Specify a day to run"
	@echo " e.g. make dayN && make run_dayN"

# Variable to store days implemented
DAYS := $(basename $(notdir $(wildcard src/day*.cpp)))

# Special rules for certain days :)

day4 : util/lib/md5.o day4.o

# Execution rules

run_all : all
	make $(addprefix run_,$(DAYS))

run_% : %
	@echo "Running $<"
	@printf "Part 1: "
	@./$< < input/$<.txt
	@printf "Part 2: "
	@./$< part2 < input/$<.txt

# Build rules

all : $(DAYS)

# Cleanup

clean :
	@-rm -v *.o util/lib/*.o

distclean : clean
	@-rm -v day*
