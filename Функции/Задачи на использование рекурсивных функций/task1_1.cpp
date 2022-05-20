#include<iostream>

using namespace std;

long long recursion(int x) { // рекурсия
    if (x > 1)
        return x * recursion(x - 1);

    else // при единице вернёт 1ж
        return 1;
}

long long func(int x) { // не рекурсия
    long long res = 1;

    for (int i = 1; i <= x; i++)
        res *= i;

    return res;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "Введите n: "; // ввод
    cin >> n;

    cout << "Факториал через рекурсию: ";
    cout << recursion(n) << endl; // вывод

    cout << "Факториал не через рекурсию: ";
    cout << func(n) << endl; // вывод

    system("pause");
    return 0;
}
