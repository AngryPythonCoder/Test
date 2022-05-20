#include<iostream>

using namespace std;

long long recursion(int k, int n) { // рекурси€
    if (k == 0)
        return 1; // способов выбрать 0 элементов всегда 1

    else
        return recursion(k - 1, n) * (n + 1 - k) / k; // вычисл€ем по формуле
}

long long factorial(int x) { // вспомогательна€ функци€
    long long res = 1;

    for (int i = 1; i <= x; i++)
        res *= i;

    return res;
}

long long func(int k, int n) { // не рекурси€
    return factorial(n) / (factorial(k) * factorial(n-k));
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, k;

    cout << "¬ведите n: "; // ввод
    cin >> n;

    cout << "¬ведите k: ";
    cin >> k;

    cout << "C из " << n << " по " << k << " через рекурсию: ";
    cout << recursion(k, n) << endl; // вывод

    cout << "C из " << n << " по " << k << " не через рекурсию: ";
    cout << func(k, n) << endl; // вывод

    system("pause");
    return 0;
}
