CC := clang++
CXX := clang++
CPPFLAGS := -Iutil/include
CXXFLAGS := -O3 -march=native -std=c++14
vpath day%.cpp src

day4 : util/lib/md5.o day4.o

run_% : %
	@echo "Running $<"
	./$< < input/$<.txt
	./$< part2 < input/$<.txt

.PHONY : clean

clean :
	@rm -v *.o util/lib/*.o
