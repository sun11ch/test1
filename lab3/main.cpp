#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");
	short kc;
	float c;
	float sumc{0};
	unsigned short nomer{0};
	float maxc{-0.36};
	bool foundc{0};
	cout << "Сколько вещественных чисел в последовательности: "; cin >> kc;
	if (kc > 0 && kc <= 32767) {
		for (unsigned short i = 1; i != kc + 1; i += 1) {
			cout << "Число " << i << ": "; cin >> c;
			if (c > -0.36 && c <= 10.1) {
				foundc = 1;
				sumc = sumc + c;
				if (c > maxc) {
					maxc = c;
					nomer = i;
				}
			}
		}
	}
	else {
		cout << "Ошибка";
		return 1;
	}
	if (foundc = 0) {
		cout << "нет чисел условия" << endl;
	}
	else {
		cout << "summa: " << sumc << endl;
		cout << "nomer max chisla: " << nomer << endl;
		cout << "max chisla: " << maxc << endl;
	}

	short c2;
	short mc2;
	short pr{1};
	cout << "Введите целое число |X|<1000: "; cin >> c2;
	mc2 = abs(c2);
	if (c2 == 0) {
		cout << "Произведение цифр числа " << c2 << ": 0" << endl;
		return 1;
	}
	while (mc2 > 0) {
		pr = pr * (mc2 % 10);
		mc2 = mc2 / 10;
	}
	cout << "Произведение цифр числа " << c2 << ": " << pr << endl;
	return 0;
}
