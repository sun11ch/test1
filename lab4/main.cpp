// ����� 1
#include <iostream>
#include <C:\Git\test1\lab4\main2.cpp>
int main() {
	//pynkt2();
	setlocale(LC_ALL, "Rus");
	std::cout << "---������� 6 ����� �������---" << std::endl;
	const int n = 6;
	int mas[n];
	for (int i = 0; i < n; i += 1) {
		std::cout << "����� " << i + 1 << ": ";  std::cin >> mas[i];
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
		std::cout << "� ������� ���� 2 ���������� ����� ������. ��������������� ������: ";
		std::cout << "[";
		for (int i = 0; i < n; i += 1) {
			std::cout << mas[i] << " ";
		}
		std::cout << "]";
	}
	else {
		std::cout << "� ������� ��� 2 ���������� ����� ������. �������� ������: ";
		std::cout << "[";
		for (int i = 0; i < n; i += 1) {
			std::cout << mas[i] << " ";
		}
		std::cout << "]";
	}


	return 0;
}