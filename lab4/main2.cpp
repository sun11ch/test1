// пункт 2
#include <iostream>
void pynkt2() {
	setlocale(LC_ALL, "Rus");
	const int strk = 3;
	const int stlb = 4;
	int matr[strk][stlb];
	for (int i = 0; i < strk; i += 1) {
		std::cout << "Введите 4 элемента " << i+1 << " строки: ";
		for (int j = 0; j < stlb; j += 1) {
			std::cin >> matr[i][j];
		}
	}
	int maxstrk = 0;
	int nmaxstrk = 0;
	for (int i = 0; i < strk; i += 1) {
		int tempsum = 0;
		for (int j = 0; j < stlb; j += 1) {
			tempsum += abs(matr[i][j]);
		}
		std::cout << "Сумма модулей элементов " << i+1 << " строки: " << tempsum << std::endl;
		if (tempsum > maxstrk) {
			maxstrk = tempsum;
			nmaxstrk = i;
		}
	}
	std::cout << "Строка " << nmaxstrk+1 << " имеет максимальную сумму модулей её элементов: " << maxstrk << std::endl;
	for (int j = 0; j < stlb; j += 1) {
		matr[nmaxstrk][j] = 0;
	}
	std::cout << "Матрица после обнуления строки " << nmaxstrk + 1 << ": " << std::endl;
	for (int i = 0; i < strk; i += 1) { 
		for (int j = 0; j < stlb; j += 1) {
			std::cout << matr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
}