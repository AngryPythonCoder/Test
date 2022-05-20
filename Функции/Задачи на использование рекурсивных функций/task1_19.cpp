#include<iostream>

using namespace std;

void special_print(int n, int border, char a) { // ����������� �����
    for (int i = 0; i < (border - n); i++) //�������
        cout << " ";

    for (int i = 0; i < (2*n + 1); i++) //�������
        cout << a;

    for (int i = 0; i < (border - n); i++) //�������
        cout << " ";

    cout << endl;
}


void recursion(int current, int border, bool generating) {
    if (current >= 0 && current <= border) {
        recursion(current-1, border, false); // ����������� ������������
        special_print(current, border, '*'); // �����

        if (generating) // ��������� ����������� �������������
            recursion(current+1, border, true);
    }
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "������� n: "; // ����
    cin >> n;

    recursion(1, n, true); //�����

    system("pause");
    return 0;
}
