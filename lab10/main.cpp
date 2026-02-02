#include "player.hpp"
#include <ctime>

int main() {
	std::srand((unsigned)std::time(nullptr));
	Player alex1("alex1", {"apple", "bow", "guard", "potion", "testitem"}, 24, 13.4, 11.7);
	Player alex2("alex2", {"sword", "bow", "potion", "grysha"}, 37, 9.2, 9.82);
	Player alex3 = alex1+alex2+alex2;
	Player alex4 = alex1-alex2;
	Player alex5 = alex1/alex2;
	alex5.printinfo();
	return 0;
}