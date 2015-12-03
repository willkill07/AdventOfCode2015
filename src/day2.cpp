#include <array>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>

using box = std::array <int, 3>;

box
parseLine (const std::string& line) {
	std::istringstream iss { line };
	std::string s;
	int index { 0 };
	box b {{ 0, 0, 0 }};
	while (std::getline (iss, s, 'x')) {
		b [ index++ ] = std::stoi (s);
	}
	return b;
}

int
main (int argc, char* argv[]) {
	bool part2 { argc == 2 };
	int total { 0 };

	std::string line;
	while (std::getline (std::cin, line)) {
		box b = parseLine (line);
		std::sort (std::begin (b), std::end (b));
		if (!part2) {
			total += 3 * b[0] * b[1] + 2 * b[2] * (b[0] + b[1]);
		} else {
			total += 2 * (b[0] + b[1]) + b[0] * b[1] * b[2];
		}
	}
	std::cout << total << std::endl;
	return 0;
}
