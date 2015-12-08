CC := clang++
CXX := clang++
CPPFLAGS := -Iutil/include
CXXFLAGS := -O3 -march=native -std=c++14 -Wall -pedantic
vpath day%.cpp src

.PHONY : all run_all clean distclean

# Variable to store days implemented
DAYS := $(basename $(notdir $(wildcard src/day*.cpp)))

# Build rules
all : $(DAYS)

# Execution rules
run_all : all
	@make $(addprefix run_,$(DAYS))

run_% : %
	@echo "Running $<"
	@printf "Part 1: "
	@./$< < input/$<.txt
	@printf "Part 2: "
	@./$< part2 < input/$<.txt

# Special rules for certain days :)
day4 : util/lib/md5.o day4.o

# Cleanup
clean :
	@-rm -v *.o util/lib/*.o

distclean : clean
	@-rm -v day*
