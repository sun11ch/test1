#include <iostream>
#include <stdlib.h>
void printmatr(int** matrix, int strki, int stlbi) {
	std::cout << "Матрица " << strki << "x" << stlbi << std::endl;
	for (int i = 0; i < strki; i+=1) {
		for (int j = 0; j < stlbi; j+=1)
			std::cout << matrix[i][j] << "   ";
		std::cout << std::endl;
	}
}
int* FindZeroColumns(int** matrix, int strki, int stlbi, int& count){
	count = 0;
	int* zeroCols = (int*)calloc(stlbi, sizeof(int));
	if (!zeroCols) return 0;
	for (int j = 0; j < stlbi; j+=1) {
		for (int i = 0; i < strki; i+=1) {
			if (matrix[i][j] == 0) {
				zeroCols[count] = j;
				count += 1;
				break;
			}
		}
	}

	if (count > 0) {
		zeroCols = (int*)realloc(zeroCols, count * sizeof(int));
		std::cout << "Столбцы для удаления: [ ";
		for (int i = 0; i < count; i++) std::cout << zeroCols[i] << " ";
		std::cout << "]" << std::endl;
	}
	return zeroCols;
}
void RemoveColumns(int** matrix, int strki, int& stlbi, int* cols, int count){
	if ((count == 0) or (cols == 0)) return;
	if (count == stlbi){
		for (int i = 0; i < strki; i += 1){
			free(matrix[i]);
			matrix[i] = 0;
		}
		stlbi = 0;
		return;
	}
	for (int i = 0; i < strki; i += 1) {
		int newJ = 0;
		for (int j = 0; j < stlbi; j += 1) {
			bool save = true;
			for (int k = 0; k < count; k += 1)
				if (j == cols[k]) { 
					save = false; 
					break; 
				}
			if (save == true) {
				matrix[i][newJ] = matrix[i][j];
				newJ+=1;
			}
		}

		int* newRow = (int*)realloc(matrix[i], (stlbi - count) * sizeof(int));
		if (newRow)
			matrix[i] = newRow;
	}
	stlbi -= count;
}
void pynkt2() {
	float* a = new float;
	float* b = new float;

	std::cout << "Введите a: "; std::cin >> *a;
	std::cout << "Введите b: "; std::cin >> *b;

	float* pa = a;
	float* pb = b;

	std::cout << "До: a= " << *pa << " b= " << *pb << std::endl;

	*pa = *pa * 3; 

	float temp = *pa;
	*pa = *pb;
	*pb = temp;

	std::cout << "После: a=" << *pa << " b=" << *pb << std::endl;

	delete a;
	delete b;

}
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

	int** matrix = (int**)malloc(2 * sizeof(int*));
	if (!matrix) return 1;
	for (int i = 0; i < 2; i++) {
		matrix[i] = (int*)malloc(2 * sizeof(int));
		if (!matrix[i]) {
			for (int j = 0; j < i; j++) 
				free(matrix[j]);
			free(matrix);
			return 2;
		}
	}

	matrix[0][0] = a;
	matrix[0][1] = b;
	matrix[1][0] = c;
	matrix[1][1] = d;
	printmatr(matrix, 2, 2);

	int strki = 2 + a;
	int stlbi = 2 + b;

	matrix = (int**)realloc(matrix, strki * sizeof(int*));
	
	for (int i = 2; i < strki; i += 1) {
		if (i < 2) {
			matrix[i] = (int*)realloc(matrix[i], stlbi * sizeof(int*));
		}
		else{
			matrix[i] = (int*)malloc(stlbi * sizeof(int));
		}
		if (!matrix[i]) {
			for (int j = 0; j < i; j+=1) 
				free(matrix[j]);
			free(matrix);
			return 5;
		}
	}



	for (int i = 0; i < strki; i+=1) {
		for (int j = 0; j < stlbi; j+=1) {
			if ((i >= 2) or (j >= 2)) {
				matrix[i][j] = (i - 1) * c + (j - 1) * d;
			}
		}
	}
	printmatr(matrix, strki, stlbi);
	int count = 0;
	int* zeroCols = FindZeroColumns(matrix, strki, stlbi, count);

	if ((zeroCols != 0) and (count > 0)) {
		RemoveColumns(matrix, strki, stlbi, zeroCols, count);
		printmatr(matrix, strki, stlbi);
		free(zeroCols);
	}
	else {
		std::cout << "Удаление не требуется." << std::endl;
	}
	for (int i = 0; i < strki; i++) {
		free(matrix[i]); 
	}
	free(matrix);
	pynkt2();
	return 0;
}