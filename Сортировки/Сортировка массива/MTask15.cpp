#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10;

void file_input(int matrix[N][N]) { // чтение из файла
    ifstream fin("input.txt"); // открытие файла

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> matrix[i][j];
}

void file_output(int matrix[N][N]) { // запись в файл
    ofstream fout("output_15.txt"); // открытие файла

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            fout << matrix[i][j] << " ";
        fout << endl;
    }
}

void insertionsort(int matrix[N][N], int diagonal) { // сортировка вставками
    int x = min(diagonal, N-1), 
        y = max(0, diagonal - (N-1)); // начальные координаты диагонали
    
    int length = -abs((N-1) - diagonal) + N; // длина диагонали

    for (int i = 1; i < length; i++) { // сортировка
        for (int j = i; j > 0 && matrix[x-(j-1)][y+(j-1)] > matrix[x-j][y+j]; j--) {
            swap(matrix[x-(j-1)][y+(j-1)], matrix[x-j][y+j]);
        }
    }
}

int main() {
    int matrix[N][N];

    file_input(matrix); // ввод

    for (int i = 0; i < (2*N - 1); i++) { // проход по диагоналям
        insertionsort(matrix, i);
    }

    file_output(matrix); // вывод

    return 0;
}