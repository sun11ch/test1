#include <iostream>
using namespace std;


int main() {
	setlocale(LC_ALL, "RUS");
	unsigned short a; // минимальный неотрицательный целочисленный тип данных
	unsigned short b; // минимальный неотрицательный целочисленный тип данных
	cout << "Number a (0-65535):";
	cin >> a;
	cout << "Number b (0-65535):";
	cin >> b;
	unsigned int sum_ab = a+b; // т.к. макс. сумма а+б = 131 070 
	int razn_ab = a-b; // числа принимают значения от -65535 до 65535
	int razn_ba = b - a;// числа принимают значения от -65535 до 65535
	unsigned int proizv_ab = a*b; // макс. число здесь 4 294 836 225
	cout << "a+b = b+a: " << sum_ab << endl;
	cout << "a-b: " << razn_ab << endl;
	cout << "b-a: " << razn_ba << endl;
	cout << "a*b = b*a: " << proizv_ab << endl;
	
	cout << "|UNSIGNED SHORT| " << "|size: 16 bits| " << "|max: " << USHRT_MAX << "| " << "|min: 0|" << endl;
	cout << "|UNSIGNED INT| " << "|size: 32 bits| " << "|max: " << UINT_MAX << "| " << "|min: 0|" << endl;
	cout << "|INT| " << "|size: 32 bit| " << "|max: " << INT_MAX << "| " << "|min: " << INT_MIN<< "|" << endl;
	return 0;
}