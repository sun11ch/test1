// пункт 1
#include <iostream>
#include "main2.cpp"
int main() {
	//pynkt2();
	setlocale(LC_ALL, "Rus");
	std::cout << "---Введите 6 чисел массива---" << std::endl;
	const int n = 6;
	int mas[n];
	for (int i = 0; i < n; i += 1) {
		std::cout << "Число " << i + 1 << ": ";  std::cin >> mas[i];
	}
	bool DCH = 0;

	for (int i = 0; i < n; i += 1) {
		if (mas[i] == mas[i + 1]) {
			DCH = 1;
			break;
		}
	}



	if (DCH == 1) {
		for (int i = 0; i < n - 1; i += 1) {
			for (int j = i + 1; j < n; j += 1) {
				if (mas[i] > mas[j]) {
					std::swap(mas[i], mas[j]);
				}
			}
		}
		std::cout << "В массиве есть 2 одинаковых числа подряд. Отсортированный по возростанию массив: ";
		std::cout << "[";
		for (int i = 0; i < n; i += 1) {
			std::cout << mas[i] << " ";
		}
		std::cout << "]";
	}
	else {
		std::cout << "В массиве нет 2 одинаковых числа подряд. Исходный массив: ";
		std::cout << "[";
		for (int i = 0; i < n; i += 1) {
			std::cout << mas[i] << " ";
		}
		std::cout << "]";
	}


	return 0;
}