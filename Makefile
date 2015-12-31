CC := clang++
CXX := clang++
CPPFLAGS := -Iutil/include
CXXFLAGS := -O3 -march=native -std=c++14 -Wall -Wextra -Werror -pedantic -pedantic-errors
FILES := $(wildcard src/*.cpp)  $(wildcard util/lib/*.cpp)
OBJECTS := $(FILES:.cpp=.o)
vpath %.cpp util/lib

.PHONY : advent run

advent : $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

run : advent
	@./adcent

clean:
	@-rm -vf $(OBJECTS)
