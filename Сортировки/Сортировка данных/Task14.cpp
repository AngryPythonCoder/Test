#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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
    ofstream fout("output_14.txt"); // открытие файла

    for (vector<person>::iterator it = people.begin(); it != people.end(); it++)
        fout << (*it).surname << " " << (*it).appointment << (((*it).birthdate.day < 10)?" 0":" ") // запись
             << (*it).birthdate.day << (((*it).birthdate.month < 10)?".0":".") << (*it).birthdate.month << "." << (*it).birthdate.year 
             << " " << (*it).experience << " " << (*it).salary << endl;
}

bool operator < (person a, person b) { // переопределённый оператор сравнения
    if (a.surname < b.surname) return true;
    if (a.surname == b.surname && a.appointment < b.appointment) return true;
    return false;
}

bool comp (person a, person b) { // переопределённый оператор сравнения
    if (a.surname < b.surname) return true;
    if (a.surname == b.surname && a.appointment < b.appointment) return true;
    return false;
}

void selectionsort(vector<person> &people) { // сортировка выбором
    int length = people.size();

    for (int i = 0; i < length; i++) {
        int index = min_element(people.begin()+(i+1), people.end(), comp)-people.begin(); // минимальный на подмассиве

        if (index < length && people[index] < people[i]) // если минимум меньше текущего элемента
            swap(people[index], people[i]); // меняем местами
    }
}

int main() {
    vector<person> people;

    file_input(people); // ввод
    
    selectionsort(people); // сортировка

    file_output(people); // вывод
    
    return 0;
}