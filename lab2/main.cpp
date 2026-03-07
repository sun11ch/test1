#include "player.hpp"
#include <ctime>

int main() {
	std::srand((unsigned)std::time(nullptr));
	Player alex1("alex1", {"sword", "bow"}, 50, 5, 5);
	Player alex2("alex2", {"sword", "bow"}, 30, 10, 10);
	// Player alex22("alex22", {}, 100, 22, 22);
	// alex2 = alex22;
	// std::cout << "alex2:  " << &alex2.getItems() << std::endl;
	// std::cout << "alex22: " << &alex22.getItems() << std::endl;
	Player alex3 = alex1+alex2;
	Player alex4 = alex1-alex2;
	Player alex5 = alex1/alex2;
	// alex3.printinfo();
	alex4.printinfo();
	// alex5.printinfo();
	return 0;
}