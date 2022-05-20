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
    ofstream fout("output_8.txt"); // открытие файла

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            fout << matrix[i][j] << " ";
        fout << endl;
    }
}

bool ascending_order(int x, int y) { // компаратор для сортировки по возрастанию
    return x < y;
}

bool descending_order(int x, int y) { // компаратор для сортировки по убыванию
    return x > y;
}

void mergesort(int arr[], int length, bool comp(int, int)) { // сортировка слиянием
    if (length > 1) {
        int separator = length/2;

        mergesort(&arr[0], separator, comp); // рекурсивная сортировка подмассивов
        mergesort(&arr[separator], length - separator, comp);

        int temp[length];
        int left_index = 0, right_index = separator, temp_index = 0;

        while (left_index < separator || right_index < (length - separator)) { // слияние
            if (comp(arr[left_index], arr[right_index]))
                temp[temp_index++] = arr[left_index++];

            else
                temp[temp_index++] = arr[right_index++];

            if (left_index == separator) { // если левый подмассив кончился
                copy(make_move_iterator(&arr[right_index]), make_move_iterator(&arr[length]), &temp[temp_index]);
                break;
            }

            if (right_index == length) { // если кончился правый подмассив
                copy(make_move_iterator(&arr[left_index]), make_move_iterator(&arr[separator]), &temp[temp_index]);
                break;
            }
        }

        copy(make_move_iterator(temp), make_move_iterator(&temp[length]), arr); // вставляем отредактированный подмассив в основной
    }
}

int main() {
    int matrix[N][N];

    file_input(matrix); // ввод

    for (int i = 0; i < N; i++) {
        if (((i+1) % 3) == 0)
            mergesort(matrix[i], N, descending_order); // по убыванию
        else
            mergesort(matrix[i], N, ascending_order); // по возрастанию
    }

    file_output(matrix); // вывод

    return 0;
}