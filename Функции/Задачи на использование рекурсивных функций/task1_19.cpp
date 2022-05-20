#include<iostream>

using namespace std;

void special_print(int n, int border, char a) { // специальный вывод
    for (int i = 0; i < (border - n); i++) //пробелы
        cout << " ";

    for (int i = 0; i < (2*n + 1); i++) //символы
        cout << a;

    for (int i = 0; i < (border - n); i++) //пробелы
        cout << " ";

    cout << endl;
}


void recursion(int current, int border, bool generating) {
    if (current >= 0 && current <= border) {
        recursion(current-1, border, false); // продолжение треугольника
        special_print(current, border, '*'); // вывод

        if (generating) // генераци€ последующих треугольников
            recursion(current+1, border, true);
    }
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "¬ведите n: "; // ввод
    cin >> n;

    recursion(1, n, true); //вызов

    system("pause");
    return 0;
}
