#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");

	float c, sumc{ 0 }, maxc{ -0.36 }, vgr{ 10.1 }, ngr{ -0.36 };
	unsigned short kc, nomer{0};
	bool foundc = false;

	cout << "Сколько вещественных чисел в последовательности (от 1 до 65535): "; cin >> kc;

	if (0 < kc <= 65535) {
		for (unsigned short i = 1; i <= kc; i += 1) {
			cout << "Число " << i << ": "; cin >> c;
			if (c > ngr && c<= vgr) {
				sumc = c+sumc;
				foundc = true;
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
	if (foundc == false){
		cout << "Нет чисел из интервала (-0,36; 10,1]:" << endl;
	}
	else {
		cout << "Сумма чисел из интервала (-0,36; 10,1]: " << sumc << endl;
		cout << "Номер максимального числа из интервала (-0,36; 10,1]:: " << nomer << endl;
		cout << "Максимальное число из интервала (-0,36; 10,1]: " << maxc << endl;
	}

	short c2;
	short mc2;
	short pr{1};
	cout << "---------------------------------------" << endl;
	cout << "Введите целое число |X|<1000: "; cin >> c2;
	mc2 = abs(c2);
	if (c2 == 0) {
		cout << "Произведение цифр числа " << c2 << ": 0" << endl;
		return 1;
	}
	if (c2 > 1000 || c2 < -1000) {
		cout << "Ошибка, вы вышли из диапазона числа X" << endl;
		return 1;
	}
	while (mc2 > 0) {
		pr = pr * (mc2 % 10);
		mc2 = mc2 / 10;
	}
	cout << "Произведение цифр числа " << c2 << ": " << pr << endl;
	return 0;
}
