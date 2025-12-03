
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
      
struct Stop {
    std::string name;
    int cost;
    Stop* next_stop;
};

Stop* create_new_stop(std::string name, int cost) {

    Stop* new_stop = new Stop(name, cost);
    new_stop->name = name;
    new_stop->cost = cost;
    return new_stop;
}

void add_new_stop(Stop* head, std::string name, int cost) {
    Stop* new_stop = create_new_stop(name, cost);
    new_stop->next_stop = head->next_stop;
    head->next_stop = new_stop;
}

void print_all_stops(Stop* head) {
    Stop* ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->name;
        if (ptr->next_stop){
            std::cout << "-->";
        }
        else {
            std::cout << std::endl;
        }
        ptr = ptr->next_stop;
    }
}

void print_all_bracnhes(std::vector<Stop*>& bracnhes) {
    std::cout << "\n------ Маршруты ------\n";
    for (int i = 0; i < bracnhes.size(); i++){
        std::cout << "Маршрут " << i + 1 << ": ";
        print_all_stops(bracnhes[i]);
    }
}

Stop* find_stop_by_name(Stop* head, const std::string& name){
    Stop* ptr = head;
    do{
        if (ptr->name == name)
            return ptr;
        ptr = ptr->next_stop;
    } while (ptr != nullptr);
    return nullptr;
}

Stop* find_prev_stop(Stop* head, const std::string name) {
    Stop* prev = nullptr;
    Stop* ptr = head;
    do {
        if (ptr->name == name) {
            return prev;
        }
        prev = ptr;
        ptr = ptr->next_stop;
    } while (ptr != nullptr);
    return nullptr;
}

void print_way_from_a_to_b(Stop* head) {
    std::string start_name;
    std::cout << "Введите название начальной остановки: ";
    std::cin >> start_name;

    std::string finish_name;
    std::cout << "Введите название конечной остановки: ";
    std::cin >> finish_name;
    Stop* start = find_stop_by_name(head, start_name);
    Stop* finish = find_stop_by_name(head, finish_name);
    if (start == nullptr) {
        std::cout << "Остановка \"" << start_name << "\" не найдена.\n";
        return;
    }
    if (finish == nullptr) {
        std::cout << "Остановка \"" << finish_name << "\" не найдена.\n";
        return;
    }
    int sum = 0;
    Stop* ptr = start;
    do {
        std::cout << ptr->name;
        if (ptr->next_stop == nullptr) {
            std::cout << " <- конечная";
        }

        if (ptr == finish){
            std::cout << "\nЦена маршрута: " << sum << "\n";
            return;
        }
        std::cout << " (" << ptr->cost << ")" << "-> ";
        sum += ptr->cost;
        ptr = ptr->next_stop;
    } while (ptr != nullptr);
}

std::vector<Stop*> StartBracnhes() {
    std::vector<Stop*> branches;

    Stop* a1 = new Stop;
    a1->cost = 10;
    a1->name = "Киевская";
    Stop* a2 = new Stop;
    a2->cost = 10;
    a2->name = "Площадь Василевского";
    Stop* a3 = new Stop;
    a3->cost = 30;
    a3->name = "Октябрьская";
    Stop* a4 = new Stop;
    a4->cost = 20;
    a4->name = "Невского";
    Stop* a5 = new Stop;
    a5->cost = 0;
    a5->name = "Театральная";
  
    a1->next_stop = a2;
    a2->next_stop = a3;
    a3->next_stop = a4;
    a4->next_stop = a5;
    a5->next_stop = nullptr;
    
    branches.push_back(a1);

    Stop* b1 = new Stop;
    b1->cost = 10;
    b1->name = "b1";
    Stop* b2 = new Stop;
    b2->cost = 0;
    b2->name = "b2";
    
    b1->next_stop = b2;
    b2->next_stop = nullptr;
  
    branches.push_back(b1);

    Stop* c1 = new Stop;
    c1->cost = 10;
    c1->name = "c1";
    Stop* c2 = new Stop;
    c2->cost = 0;
    c2->name = "c2";

    c1->next_stop = c2;
    c2->next_stop = nullptr;
    branches.push_back(c1);
 


    return branches;
}
void add_ost_after_another(Stop* head) {
    std::cout << "Введите имя остановки, после которой добавить новую: ";
    std::string foundname;
    std::cin >> foundname;
    Stop* ptr1 = find_stop_by_name(head, foundname);
    Stop* ptrlast = find_prev_stop(head, foundname);
    if (ptr1->next_stop == nullptr) {
        std::cout << "Т.к. остановка конечная, цена до следующей будет 0" << std::endl;
        std::cout << "Введите имя новой остановки: ";
        std::string name;
        std::cin >> name;
        std::cout << "Введите цену от предыдущей остановки до нынешней";
        int lastcost;
        std::cin >> lastcost;
        ptrlast->cost = lastcost;
        Stop* newStop = create_new_stop(name, 0);
        newStop->next_stop = nullptr;
        ptr1->next_stop = newStop;
    }
    else {
        std::cout << "Введите имя новой остановки: ";
        std::string name;
        std::cin >> name;
        std::cout << "Введите цену до следующей остановки: ";
        int cost;
        std::cin >> cost;
        if (ptrlast != nullptr) {
            ptrlast->cost = cost;
        }
        else {
            Stop* newStop = create_new_stop(name, cost);
            newStop->next_stop = ptr1->next_stop;
            ptr1->next_stop = newStop;
        }
    }
}

int main() {
    SetConsoleCP(1251); //для ввода по русски
    SetConsoleOutputCP(1251); //для вывода по русски
    setlocale(LC_ALL, "Russian"); // на всякий случай

    std::vector<Stop*> branches = StartBracnhes();
    int pynkt;

    do {
        std::cout << "\n------Меню------\n" << std::endl;
        std::cout << "Какой пункт выполнить?" << std::endl;
        std::cout << "0: Выход из программы" << std::endl;
        std::cout << "1: Просмотр всех маршрутов" << std::endl;
        std::cout << "2: Показать путь из точки А в точку Б" << std::endl;
        std::cout << "3: Добавить остановку после выбранной" << std::endl;
        std::cout << "4: Создать новую остановку на новом маршруте" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> pynkt;
        if (pynkt == 0) {
            std::cout << "Выход из программы";
            return 1;
        }
        else if (pynkt == 1) {
            print_all_bracnhes(branches);
        }
        else if (pynkt == 2) {
            std::cout << "Выберите маршрут: ";
            int q; std::cin >> q;
            print_way_from_a_to_b(branches[q-1]);
        }
        else if (pynkt == 3) {
            std::cout << "Выберите маршрут: ";
            int q; std::cin >> q;
            add_ost_after_another(branches[q-1]);
        }
        else if (pynkt == 4) {
            std::cout << "Введите имя остановки: ";
            std::string name;
            std::cin >> name;
            Stop* new_branch = new Stop;
            new_branch->name = name;
            new_branch->cost = 0;
            new_branch->next_stop = nullptr;
            branches.push_back(new_branch);
            std::cout << "Новый маршрут создан";
        }

    } while (pynkt != 0);
    return 0;
}



