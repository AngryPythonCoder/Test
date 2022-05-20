#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct date { // дата
    int day, month, year;
};

struct person { // человек
    string surname, appointment;
    date birthdate;
    int experience, salary;
};

date string_to_date(string str) { // извлечение даты из строки
    date result;

    result.day = stoi(str.substr(0, 2));    // день
    result.month = stoi(str.substr(3, 2));  // месяц
    result.year = stoi(str.substr(6, 4));   // год

    return result;
}

void file_input(vector<person> &people) { // чтение из файла
    person current;
    string s;

    ifstream fin("input.txt"); // открытие файла

    while (fin.peek() != EOF) { // чтение данных
        fin >> current.surname;
        fin >> current.appointment;
        fin >> s;
        current.birthdate = string_to_date(s);
        fin >> current.experience;
        fin >> current.salary;

        people.push_back(current); // занесение в список
    }
}

void file_output(vector<person> &people) { // запись в файл
    ofstream fout("output_5.txt"); // открытие файла

    for (vector<person>::iterator it = people.begin(); it != people.end(); it++)
        fout << (*it).surname << " " << (*it).appointment << (((*it).birthdate.day < 10)?" 0":" ") // запись
             << (*it).birthdate.day << (((*it).birthdate.month < 10)?".0":".") << (*it).birthdate.month << "." << (*it).birthdate.year 
             << " " << (*it).experience << " " << (*it).salary << endl;
}

bool operator < (person a, person b) { // переопределённый оператор сравнения
    return a.appointment < b.appointment;
}

void sift_down(vector<person> &people, int current, int length) { // функция просеивания вниз
    bool done = false;

    int largest = current;
    int left = 2*current + 1;   // левый сын
    int right = 2*current + 2; // правый сын
 
    if (left < length && people[largest] < people[left])
        largest = left;
 
    if (right < length && people[largest] < people[right])
        largest = right;
 
    if (largest != current) { // если какой-то из сыновей больше родителя
        swap(people[largest], people[current]);
        sift_down(people, largest, length); // рекурсивная обработка затронутого поддерева
    }
}

void heapsort(vector<person> &people) { // пирамидальная сортировка
    int length = people.size();

    for (int i = length/2 - 1; i >= 0; i--) // построение кучи
        sift_down(people, i, length);
 
    for (int i = length-1; i >= 0; i--) { // сортировка
        swap(people[0], people[i]);
        sift_down(people, 0, i);
    }
}

int main() {
    vector<person> people;

    file_input(people); // ввод
    
    heapsort(people); // сортировка

    file_output(people); // вывод
    
    return 0;
}