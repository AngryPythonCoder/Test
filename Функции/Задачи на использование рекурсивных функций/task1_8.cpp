#include<iostream>

using namespace std;

long long recursion(int k, int n) { // ��������
    if (k == 0)
        return 1; // �������� ������� 0 ��������� ������ 1

    else
        return recursion(k - 1, n) * (n + 1 - k) / k; // ��������� �� �������
}

long long factorial(int x) { // ��������������� �������
    long long res = 1;

    for (int i = 1; i <= x; i++)
        res *= i;

    return res;
}

long long func(int k, int n) { // �� ��������
    return factorial(n) / (factorial(k) * factorial(n-k));
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, k;

    cout << "������� n: "; // ����
    cin >> n;

    cout << "������� k: ";
    cin >> k;

    cout << "C �� " << n << " �� " << k << " ����� ��������: ";
    cout << recursion(k, n) << endl; // �����

    cout << "C �� " << n << " �� " << k << " �� ����� ��������: ";
    cout << func(k, n) << endl; // �����

    system("pause");
    return 0;
}
