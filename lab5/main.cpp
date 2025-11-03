#include <iostream>
void Laba1(int a, int b) {
	std::cout << "Используется функция вычисления попарной суммы/разности/произведения/частного";
	int sum_ab = a + b; 
	int razn_ab = a - b; 
	int razn_ba = b - a;
	int proizv_ab = a * b; 
	float delenie_ab = static_cast<float>(a) / b; 
	float delenie_ba = static_cast<float>(b) / a; 
	std::cout << "a+b = b+a: " << sum_ab << std::endl;
	std::cout << "a-b: " << razn_ab << std::endl;
	std::cout << "b-a: " << razn_ba << std::endl;
	std::cout << "a*b = b*a: " << proizv_ab << std::endl;
	std::cout << "a/b = " << delenie_ab << std::endl;
	std::cout << "b/a = " << delenie_ba << std::endl;
}
int Chisla(int a, int b) {
	std::cout << "Используется функция кратности двух чисел" << std::endl;
	if (a == b) {
		std::cout << "Числа кратны друг другу. Результат их деления: " << a / b;
		return a / b;
	}
	if (a % b == 0) {
		std::cout << "Число " << a << " кратно числу " << b << ". Результат деления " << a << " на " << b << ": " << a / b << std::endl;
		return a / b;
	}
	else if (b % a == 0) {
		std::cout << "Число " << b << " кратно числу " << a << ". Результат деления " << b << " на " << a << ": " << b / a << std::endl;
		return b / a;
	}
	else {
		std::cout << "Число " << a << " не кратно числу " << b << " и число " << b << " не кратно числу " << a << ". Результат их произведения: " << a * b << std::endl;
		return a * b;
	}
}
int Chisla(int a, int b, int c) {
	std::cout << "Используется функция определения равности трех чисел" << std::endl;
	if ((a == b) and (b == c)) {
		std::cout << "Три числа равны друг другу";
		return 1;
	}
	else {
		std::cout << "Три числа не равны друг другу";
		return -1;
	}
}
void VyborPynkta(int a, int b) {
	if ((a >= 1) and (b >= 1)) {
		int p;
		std::cout << "Какой пункт следуюет выполнить (1 или 2): "; std::cin >> p;
		if (p == 1) {
			Laba1(a, b);
		}
		else if (p == 2) {
			Chisla(a, b);
		}
	}
	else {
		Chisla(a, b);
	}
}
int main() {
	setlocale(LC_ALL, "Rus");
	std::cout << "Введите три целых числа" << std::endl;
	int ch1, ch2, ch3;
	std::cout << "Число 1: "; std::cin >> ch1;
	std::cout << "Число 2: "; std::cin >> ch2;
	std::cout << "Число 3: "; std::cin >> ch3;

	if ((ch1 != 0) and (ch2 != 0) and (ch3 != 0)) {
		Chisla(ch1, ch2, ch3);
	}
	else if ((ch1 != 0) and (ch2 != 0) and (ch3 == 0)) {
		VyborPynkta(ch1, ch2);
	}
	else if ((ch1 != 0) and (ch2 == 0) and (ch3 != 0)) {
		VyborPynkta(ch1, ch3);
	}
	else if ((ch1 == 0) and (ch2 != 0) and (ch3 != 0)) {
		VyborPynkta(ch3, ch2);
	}
	else {
		std::cout << "Error";
		return 30;
	}
	return 0;
}