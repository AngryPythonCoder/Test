#include<iostream>

using namespace std;

int recursion(int x) {
    if (x != 0) {
        recursion(x >> 1); // ������� ����� �������� �� ��������� ��������

        cout << (x & 1); //����� ����� ���������������� �������, �.�. ������ ������� - ��������� �����
    }
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "������� n: "; // ����
    cin >> n;

    cout << "�������� �������������: ";

    if (n == 0) //������� ��� ����
        cout << 0;

    else {
        if (n < 0) // ������� ��� �������������
            cout << '-';

        recursion(abs(n)); // ����� ��������
    }

    cout << endl;

    system("pause");
    return 0;
}
