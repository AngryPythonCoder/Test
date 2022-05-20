#include<iostream>

using namespace std;

long long recursion(int x) { // ��������
    if (x > 1)
        return x * recursion(x - 1);

    else // ��� ������� ����� 1�
        return 1;
}

long long func(int x) { // �� ��������
    long long res = 1;

    for (int i = 1; i <= x; i++)
        res *= i;

    return res;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "������� n: "; // ����
    cin >> n;

    cout << "��������� ����� ��������: ";
    cout << recursion(n) << endl; // �����

    cout << "��������� �� ����� ��������: ";
    cout << func(n) << endl; // �����

    system("pause");
    return 0;
}
