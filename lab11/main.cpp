#include "player.hpp"

int main() {
	std::srand((unsigned)std::time(nullptr));
	Player alex2("df", {bow}, 10, 1, 1);
	alex2.printinfo();
	return 0;
}