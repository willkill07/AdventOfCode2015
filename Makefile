CC := clang++
CXX := clang++
CPPFLAGS := -Iutil/include -std=c++14 -MMD -O3 -march=native
CXXFLAGS := -emit-llvm -Wall -Wextra -Werror -pedantic -pedantic-errors -Wno-gnu-zero-variadic-macro-arguments
FILES := $(wildcard src/*.cpp)  $(wildcard util/lib/*.cpp)
OBJECTS := $(FILES:.cpp=.o)
DEPENDS := $(FILES:.cpp=.d)

.PHONY : run clean

advent : $(OBJECTS)
	$(CXX) $(CPPFLAGS) $^ -o $@

run : advent
	@./$<

clean:
	@-rm -vf $(OBJECTS)

-include $(DEPENDS)
