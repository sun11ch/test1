#include <iostream>
using namespace std;

int main() {
    int a, b, sum, umn, deln;
    cout << "Num a:";
    cin >> a;
    cout << "Num b:";
    cin >> b;

    umn = a*b, deln = a/b, sum = a + b;

    cout << "a+b:" << sum << endl;
    cout << "a/b:" << deln << endl;
    cout << "a*b:" << umn<< endl;
   


    return 0;
}