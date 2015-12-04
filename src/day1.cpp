#include <iostream>

int main (int argc, char* argv[]) {
	bool part2 { argc == 2 };
	int floor { 0 };
	int count { 0 };

	char c;
	while (std::cin >> c) {
		++count;
		floor += (c == ')') ? -1 : 1;
		if (part2 && floor == -1) {
			std::cout << count << std::endl;
		}
	}
	if (!part2) {
		std::cout << floor << std::endl;
	}
}
