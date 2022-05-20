#include<iostream>

using namespace std;

template <typename my_type>
void arr_in(my_type *arr, int n) { // функция ввода массива из консоли
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

template <typename my_type>
void matrix_in(my_type **matr, int n, int m) { // функция ввода матрицы
    for (int i = 0; i < n; i++) {
        matr[i] = new my_type[m];

        for (int j = 0; j < m; j++)
            cin >> matr[i][j];
    }
}


template <typename my_type>
void matrix_out(my_type **matr, int n, int m) { // функция вывода
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matr[i][j] << " ";

        cout << endl;
    }
}

template <typename my_type>
void task(my_type **matr, int n, my_type *row) { //выполнение задания
    for(int i = 0; i < (n + 1) / 2; i++)
        matr[2*i] = row;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, m, k;

    cout << "Введите '<n> <m> <k>', k: 0 - int, 1 - float, 2 - char" << endl;

    cin >> n >> m >> k;

    switch(k) { //вызов различных типов данных
        case 0: {
            int *arr = new int[n];
            int **matr = new int *[n];

            cout << "Массив x: ";
            arr_in(arr, m);

            cout << endl << "Начальная матрица:" << endl;
            matrix_in(matr, n, m);

            task(matr, n, arr);

            cout << endl << "Конечная матрица:" << endl;
            matrix_out(matr, n, m);
            break;
        }

        case 1: {
            float *arr = new float[n];
            float **matr = new float *[n];

            cout << "Массив x: ";
            arr_in(arr, m);

            cout << endl << "Начальная матрица:" << endl;
            matrix_in(matr, n, m);

            task(matr, n, arr);

            cout << endl << "Конечная матрица:" << endl;
            matrix_out(matr, n, m);
            break;
        }


        case 2: {
            char *arr = new char[n];
            char **matr = new char *[n];

            cout << "Массив x: ";
            arr_in(arr, m);

            cout << endl << "Начальная матрица:" << endl;
            matrix_in(matr, n, m);

            task(matr, n, arr);

            cout << endl << "Конечная матрица:" << endl;
            matrix_out(matr, n, m);
            break;
        }
    }

    system("pause");
    return 0;
}
