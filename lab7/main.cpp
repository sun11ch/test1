#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstdlib>
#include <random>


void printVector(const std::vector<int>& v) {
    std::cout << "[ ";
    for (int i = 0; i < v.size(); i += 1) {
        int x = v[i];
        std::cout << x << " ";
    }
    std::cout << "]" << std::endl;
}

void SearchElements(std::vector<int>& v, int value) {
    bool Founded = false;
    std::cout << "Индексы: [";
    for (int i = 0; i < v.size(); i += 1) {
        if (v[i] == value) {
            if (Founded) {
                std::cout << ",";
            }
            std::cout << i;
            Founded = true;
        }
    }
    std::cout << "]" << std::endl;
}

void variant3(std::vector<int>& v) {
    std::cout << "До: ";
    printVector(v);

    if (v.empty()) {
        std::cout << "Массив пустой." << std::endl;
        return;
    }

    int mx = *std::max_element(v.begin(), v.end());
    int count = std::count(v.begin(), v.end(), mx);
    if (count == 1) {
        v.insert(v.begin(), mx);
    }
    else {
  
        v.erase(std::remove(v.begin(), v.end(), mx), v.end());
        int temp = mx;
        v.push_back(temp);
    }

    std::cout << "После: ";
    printVector(v);
}

void sortByValue(std::array<int, 10> arr) {
    std::sort(arr.begin(), arr.end());
    std::cout << "sortByValue (копия): ";
    for (int x : arr) std::cout << x << " ";
    std::cout << " ";
}

void sortByReference(std::array<int, 10>& arr) {
    std::sort(arr.begin(), arr.end());
}

void sortByPointer(std::array<int, 10>* arr) { 
    std::sort(arr->begin(), arr->end());
}

void printArray(const std::array<int, 10>& arr) {
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";
}

void runPart1() {
    std::cout << "Введите количество элементов массива: ";
    int n;
    std::cin >> n;
    if (n < 0) {
        std::cout << "Неверный ввод." << std::endl;
        return;
    }

    std::vector<int> v(n);
    std::cout << "Введите " << n << " элементов: ";
    for (int i = 0; i < n; i += 1) {
        std::cin >> v[i];
    }

    int choice;
    do {
        std::cout << "МЕНЮ (Пункт 1)" << std::endl;
        std::cout << "0. Назад" << std::endl;
        std::cout << "1. Просмотр массива" << std::endl;
        std::cout << "2. Добавить элемент в начало" << std::endl;
        std::cout << "3. Добавить элемент в конец" << std::endl;
        std::cout << "4. Очистить массив" << std::endl;
        std::cout << "5. Поиск элемента" << std::endl;
        std::cout << "6. Вариант 3" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        if (choice == 1) {
            printVector(v);
        }
        else if (choice == 2) {
            int x;
            std::cout << "Введите число: ";
            std::cin >> x;
            v.insert(v.begin(), x);
        }
        else if (choice == 3) {
            int x;
            std::cout << "Введите число: ";
            std::cin >> x;
            v.push_back(x);
        }
        else if (choice == 4) {
            v.clear();
        }
        else if (choice == 5) {
            int x;
            std::cout << "Введите число для поиска: ";
            std::cin >> x;
            SearchElements(v, x);
        }
        else if (choice == 6) {
            variant3(v);
        }

    } while (choice != 0);
}
void runPart2() {
    std::cout << "\n===== Пункт 2 (std::array) =====\n";

    std::array<int, 10> arr;
    for (int& x : arr) x = std::rand() % 21 - 10; // [-10; 10]

    std::cout << "Исходный массив: ";
    printArray(arr);

    sortByValue(arr);

    sortByReference(arr);
    std::cout << "После сортировки по ссылке: ";
    printArray(arr);

    std::mt19937 rng(static_cast<unsigned>(time(nullptr)));
    std::shuffle(arr.begin(), arr.end(), rng);
    std::cout << "После перемешивания: ";
    printArray(arr);

    sortByPointer(&arr);
    std::cout << "После сортировки по указателю: ";
    printArray(arr);

    std::cout << "\n(Пункт 2 выполнен)\n";
}
void runPart3() {
    std::cout << "vector был выбран, потому что это динамический массив." << std::endl;
    std::cout << "array был выбран, потому что это массив фиксированной длины." << std::endl;
}
int main() {
    std::setlocale(LC_ALL, "Russian");
    int mainChoice;
    do {
        std::cout << "ГЛАВНОЕ МЕНЮ" << std::endl;
        std::cout << "1. Пункт 1 (массивом и меню)" << std::endl;
        std::cout << "2. Пункт 2 (std::array + сортировки)" << std::endl;
        std::cout << "3. Пункт 3 (объяснительная)" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите пункт: ";
        std::cin >> mainChoice;
        if (mainChoice == 1) {
            runPart1();
        }
        else if (mainChoice == 2) {
            runPart2();
        }
        else if (mainChoice == 3) {
            runPart3();
        }
    } while (mainChoice != 0);

    std::cout << "Выход";
    return 0;
}