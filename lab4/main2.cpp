// ����� 2
#include <iostream>
void pynkt2() {
	setlocale(LC_ALL, "Rus");
	const int strk = 3;
	const int stlb = 4;
	int matr[strk][stlb];
	for (int i = 0; i < strk; i += 1) {
		std::cout << "������� 4 �������� " << i+1 << " ������: ";
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
		std::cout << "����� ������� ��������� " << i+1 << " ������: " << tempsum << std::endl;
		if (tempsum > maxstrk) {
			maxstrk = tempsum;
			nmaxstrk = i;
		}
	}
	std::cout << "������ " << nmaxstrk+1 << " ����� ������������ ����� ������� � ���������: " << maxstrk << std::endl;
	for (int j = 0; j < stlb; j += 1) {
		matr[nmaxstrk][j] = 0;
	}
	std::cout << "������� ����� ��������� ������ " << nmaxstrk + 1 << ": " << std::endl;
	for (int i = 0; i < strk; i += 1) { 
		for (int j = 0; j < stlb; j += 1) {
			std::cout << matr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
}