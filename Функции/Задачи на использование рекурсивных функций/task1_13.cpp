#include<iostream>

using namespace std;

int recursion(int x) {
    if (x != 0) {
        recursion(x >> 1); // сначала вызов рекурсии от остальных разр€дов

        cout << (x & 1); //далее вывод соответствующего остатка, т.к. первый остаток - последн€€ цифра
    }
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "¬ведите n: "; // ввод
    cin >> n;

    cout << "ƒвоичное представление: ";

    if (n == 0) //костыль дл€ нул€
        cout << 0;

    else {
        if (n < 0) // костыль дл€ отрицательных
            cout << '-';

        recursion(abs(n)); // вызов рекурсии
    }

    cout << endl;

    system("pause");
    return 0;
}
