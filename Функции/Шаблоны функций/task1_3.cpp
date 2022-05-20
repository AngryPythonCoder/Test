#include<iostream>

using namespace std;

template <typename my_type>
void matrix_in(my_type **matr, int n, int m) { // ������� ����� �������
    for (int i = 0; i < n; i++) {
        matr[i] = new my_type[m];

        for (int j = 0; j < m; j++)
            cin >> matr[i][j];
    }
}


template <typename my_type>
void matrix_out(my_type **matr, int n, int m) { // ������� ������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matr[i][j] << " ";

        cout << endl;
    }
}

template <typename my_type>
void task(my_type **arr, int n) { // ������
    for(int i = 0; i < n / 2; i++)
        swap(arr[2*i], arr[2*i+1]);
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, m, k;

    cout << "������� '<n> <m> <k>', k: 0 - int, 1 - float, 2 - char" << endl;

    cin >> n >> m >> k;

    switch(k) { // ����� ��������� ����� ������
        case 0: {
            int **matr = new int *[n];

            cout << endl << "��������� �������: " << endl; // ����
            matrix_in(matr, n, m);

            cout << endl;
            task(matr, n); // ���������� �������

            cout << "�������� �������: " << endl; // �����
            matrix_out(matr, n, m);
            break;
        }

        case 1: { // ���������� ��� float
            float **matr = new float *[n];

            cout << endl << "��������� �������: " << endl;
            matrix_in(matr, n, m);

            cout << endl;
            task(matr, n);

            cout << "�������� �������: " << endl;
            matrix_out(matr, n, m);
            break;
        }

        case 2: { // ���������� ��� char
            char **matr = new char *[n];

            cout << endl << "��������� �������: " << endl;
            matrix_in(matr, n, m);

            cout << endl;
            task(matr, n);

            cout << "�������� �������: " << endl;
            matrix_out(matr, n, m);
            break;
        }
    }

    system("pause");
    return 0;
}
