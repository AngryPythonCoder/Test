#include <iostream>

using namespace std;

template <typename T>
struct stack { // стек
    T value;
    stack *next;
};

template <typename T>
void push(stack<T> *&head, T value) { // операция добавления в стек
    stack<T> *temp = new stack<T>; // новое звено
    temp->value = value;
    temp->next = head;

    head = temp; // перенос головы
}

template <typename T>
T pop(stack<T> *&head) { // операция удаления из стека
    T value = head->value; // сохранение значения
    stack<T> *temp = head; // запоминание головы для удаления
    head = head->next; // перенос головы

    delete temp;
    return value;
}

void write_expression(stack<string> *&expression, string input) { // записываем выражение в стек
    input += ' '; // терминальный пробел
    int left = 0, right; // границы

    while (left < input.length()) {
        right = input.find_first_of(' ', left);
        push(expression, input.substr(left, right-left)); // записываем в стек операнд или операцию

        left = right+1;
    }
}

bool is_operation(string s) { 
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

int make_operation(int a, int b, string operation) { // выполнение операции
    if (operation == "+") return a+b;
    else if (operation == "-") return a-b;
    else if (operation == "*") return a*b;
    else return a/b; // так как работаем с int'ами, то деление целочисленное
}

int calculate_answer(stack<string> *&expression, stack<int> *&operands) { // функция подсчёта
    while (expression) {
        string something = pop(expression);

        if (is_operation(something)) { // если вытащили из стека операцию
            int first = pop(operands); // достаём два последних операнда
            int second = pop(operands); // из отдельного стека

            push(operands, make_operation(first, second, something)); // подсчитываем операцию и записываем обратно
        } 
        else {
            push(operands, stoi(something)); // иначе записываем в стек операндов
        }
    }
    return pop(operands);
}

int main() {
    string input;
    bool console = false; // ввод через консоль

    if (console) getline(cin, input);
    else input = "+ 5 / * 30 4 - 19 2";

    // надо заметить, что программа подсчитывает многозначные числа
    // но, поэтому, все операции и числа должны быть разделены пробелами (одиночными)

    stack<string> *expression = NULL; // стек для хранения выражения
    write_expression(expression, input); // запись

    stack<int> *operands = NULL; // стек для операндов
    cout << calculate_answer(expression, operands) << endl; // подсчёт и вывод

    return 0;
}