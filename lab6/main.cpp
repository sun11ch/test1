#include <iostream>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "Rus");
	int a, b, c, d;
	do {
		std::cout << "Введите A: ";  std::cin >> a;
		std::cout << "Введите B: ";  std::cin >> b;
		if ((a < 0) or (b < 0)) {
			std::cout << "Ошибка, A и B должны быть неотрицательные" << std::endl;
		}
	} while ((a < 0) or (b<0));
	std::cout << "Введите C (коэффициент строк): "; std::cin >> c;
	std::cout << "Введите D (коэффициент столбцов): "; std::cin >> d;
	int matr2x2[2][2];
	matr2x2[0][0] = a;
	matr2x2[0][1] = b;
	matr2x2[1][0] = c;
	matr2x2[1][1] = d;

	int strki = 2 + a;
	int stlbi = 2 + b;

	int** extmatr = (int**)calloc(strki, sizeof(int*));
	if (!extmatr) {
		std::cerr << "Ошибка выделения памяти для сток";
		return 1;
	}

	for (int i = 0; i < strki; i++) {
		extmatr[i] = (int*)calloc(stlbi, sizeof(int));
		if (!extmatr[i]) {
			std::cerr << "Ошибка выделения памяти для столбцов!\n";
			return 1;
		}
	}


	for (int i = 0; i < strki; i++) {
		for (int j = 0; j < stlbi; j++) {
			if ((i < 2) and (j < 2)) {
				extmatr[i][j] = matr2x2[i][j];
			}
			else {
				extmatr[i][j] = (i - 1) * c + (j - 1) * d;
			}
		}
	}

	std::cout << "Преобразованная матрица: " << std::endl;
	for (int i = 0; i < strki; i++) {
		for (int j = 0; j < stlbi; j++) {
			std::cout << extmatr[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < strki; i+=1) {
		free(extmatr[i]);
	}
	free(extmatr);

	int bvd;
	std::cin >> bvd;

	return 0;
}