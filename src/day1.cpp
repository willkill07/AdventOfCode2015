#include <iostream>

int main (int ac, char* av[]) {
	int floor { 0 };
	int count { 0 };
	bool part2 { ac == 2 };

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
