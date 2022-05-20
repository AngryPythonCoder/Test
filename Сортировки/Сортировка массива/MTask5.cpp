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
    ofstream fout("output_5.txt"); // открытие файла

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            fout << matrix[i][j] << " ";
        fout << endl;
    }
}

void sift_down(int matrix[N][N], int column, int current, int length) { // функция просеивания вниз
    bool done = false;

    int largest = current;
    int left = 2*current + 1;   // левый сын
    int right = 2*current + 2; // правый сын
 
    if (left < length && matrix[largest][column] < matrix[left][column])
        largest = left;
 
    if (right < length && matrix[largest][column] < matrix[right][column])
        largest = right;
 
    if (largest != current) { // если какой-то из сыновей больше родителя
        swap(matrix[largest][column], matrix[current][column]);
        sift_down(matrix, column, largest, length); // рекурсивная обработка затронутого поддерева
    }
}

void heapsort(int matrix[N][N],  int column) { // пирамидальная сортировка
    int length = N;

    for (int i = length/2 - 1; i >= 0; i--) // построение кучи
        sift_down(matrix, column, i, length);
 
    for (int i = length-1; i >= 0; i--) { // сортировка
        swap(matrix[0][column], matrix[i][column]);
        sift_down(matrix, column, 0, i);
    }
}

int main() {
    int matrix[N][N];

    file_input(matrix); // ввод

    for (int i = 0; i < N; i++)
        heapsort(matrix, i);    

    file_output(matrix); // вывод

    return 0;
}