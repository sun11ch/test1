#include "pynkt1.hpp"
#include "includes.hpp"
char toLowerC(char c){
    if (c >= 'А' && c <= 'Я') return c+32;
    if (c == 'Ё') return c+16;
    return c;
}
char glas[] = {'а', 'е', 'ё', 'и', 'о', 'у', 'ъ', 'ы', 'ь', 'э', 'ю', 'я'};
char sogl[] = {'б', 'в', 'г', 'д', 'ж', 'з', 'й', 'к', 'л', 'м', 'н', 'п', 'р', 'с', 'т', 'ф', 'х', 'ц', 'ч', 'ш', 'щ'};

bool isGlas(char c){
    char let = toLowerC(c);
    for (int i = 0; i < 12; i++){
        if (let == glas[i]) return true;
    }
    return false;
}
void fon(){
    char str [101];
    char result[101];
    int k = 0;
    std::cout << "Введите строку: ";
    std::cin.getline(str, 101);

    for (int i = 0; str[i] != '\0'; i++){
        if (isGlas(str[i]) == false){
            result[k] = str[i];
            k++;
        }
    }

    result[k] = '\0';

    std::cout << "Строка без гласных: " << result << std::endl;
}