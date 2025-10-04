#include <iostream>
#include <bitset>
using namespace std;


int main() {
	setlocale(LC_ALL, "RU");

	short A;
	unsigned short nomerbitaI;
	bool znacheniebitaI;

	cout << "Число A (от -32768 до 32767): "; cin >> A;

	bitset<8> a8 = A;

	cout << A << " в двоичной системе (первые 8 бит): "<< a8 << endl;
	cout << "Бит (от 0 до 7): "; cin >> nomerbitaI;

	znacheniebitaI = (A >> nomerbitaI) & 1;

	if ((nomerbitaI >7) || (nomerbitaI <0 )){
		cout << "Ошибка";
		return 1;
	}

	cout << "Значение бита под номером " << nomerbitaI << ": " << znacheniebitaI << endl;

	if (znacheniebitaI != 0)
	{
		int ch1;
		int ch2;

		cout << "Чилсло 1: ";
		cin >> ch1;
		cout << "Чилсло 2: ";
		cin >> ch2;

		if (ch1 % ch2 == 0) {
			cout << ch1 << "/" << ch2 << " = " << ch1 / ch2 << endl;

		}
		else if (ch2 % ch1 == 0) {
			cout << ch2 << "/" << ch1 << " = " << ch2 / ch1 << endl;
		}
		else {
			cout << ch1 << "*" << ch2 << " = " << ch1 * ch2 << endl;
		}

	}

	else {
		A = A ^ (1 << (nomerbitaI - 1) );
		a8 = A ^ (1 << (nomerbitaI + 1) );
		cout << "Обртаное двоичное число: " << a8 << endl;
		cout << "Обртаное десятичное число: " << a8.to_ullong() << endl;
	}
	
	cout << "-----------------" << endl;
	int N;
	cout << "Число N: ";
	cin >> N;

	switch (N){
		case 1:
			cout << "Неисправность ЭБУ впрыска" << endl;
			break;
		case 2:
			cout << "Неисправность ДУТ" << endl;
			break;
		case 4:
			cout << "Повышенное напряжение" << endl;
			break;
		case 8:
			cout << "Пониженное напряжение" << endl;
			break;
		case 13:
			cout << "Отсутствует сигнал датчика кислорода" << endl;
			break;
		case 51:
			cout << "Неисправность работы ПЗУ" << endl;
			break;
		case 52:
			cout << "Неисправность работы ОЗУ" << endl;
			break;
		case 55:
			cout << "Слишком бедная смесь" << endl;
			break;
		case 61:
			cout << "Проблемы в датчике кислорода" << endl;
			break;
		default:
			cout << "Ошибка не найдена" << endl;
			break;
	}
	return 0;
}
