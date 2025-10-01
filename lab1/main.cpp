#include <iostream>
#include <limits>
using namespace std;


int main() {
	/*
	добавить многострочный комментарий - есть
	добавить деление - есть
	исправить вывод типа данных - почти есть
	*/
	unsigned short a; // минимальный неотрицательный целочисленный тип данных
	unsigned short b; // минимальный неотрицательный целочисленный тип данных
	cout << "Number a (0-65535):";
	cin >> a;
	cout << "Number b (0-65535):";
	cin >> b;
	unsigned int sum_ab = a+b; // т.к. макс. сумма а+б = 131 070 
	int razn_ab = a-b; // числа принимают значения от -65535 до 65535
	int razn_ba = b-a;// числа принимают значения от -65535 до 65535
	unsigned int proizv_ab = a*b; // макс. число здесь 4 294 836 225
	float delenie_ab = static_cast<float>(a) / b; // чтоб не терять дробную часть
	float delenie_ba = static_cast<float>(b) / a; // то-же самое
	cout << "a+b = b+a: " << sum_ab << endl;
	cout << "a-b: " << razn_ab << endl;
	cout << "b-a: " << razn_ba << endl;
	cout << "a*b = b*a: " << proizv_ab << endl;
	cout << "a/b = " << delenie_ab << endl;
	cout << "b/a = " << delenie_ba << endl;
	
	/// название типа данных, размер в битах, максимальное и минимальное значение посчитанное формулой (можно в экс. формате)
	cout << "|UNSIGNED SHORT| " << "|size: " << sizeof(short) * 8 << " bits| " << "|max: " << pow(2, sizeof(short) * 8) -1 << "| "<< "|min: " << numeric_limits<unsigned short>::min()<< "|" << endl;

	cout << "|UNSIGNED INT| " << "|size: " << sizeof(int) * 8 << " bits| " << "|max: " << pow(2, sizeof(int)*8) -1<< "| " << "|min: "<< numeric_limits<unsigned int>::min()<< "|" << endl;

	cout << "|INT| " << "|size: " << sizeof(int)*8 << " bits| " << "|max: " << pow(2, sizeof(int) * 8 - 1)<< "| " << "|min: " << -pow(2, sizeof(int) * 8 - 1) << "|" << endl;

	cout << "|FLOAT| " << "|size: " << sizeof(float) * 8 << " bits|" << "|max: " << FLT_MAX << "| " << "|min: " << FLT_MIN << "|" << endl;
}
