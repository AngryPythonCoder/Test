#include <iostream>

int fib(int n) {
    int last = 0, next = 1;

    if (n > 2)
        for (int i = 3; i <= n; i++)
            std::swap(last += next, next);

    return (n>2)?next:n-1;
}

void fib2(int n) {
    int last = 0, next = 1;

    std::cout << last << std::endl;
    if (n > 1) std::cout << next << std::endl;
    if (n > 2)
        for (int i = 3; i <= n; i++) {
            std::swap(last, next);
            next += last;

            std::cout << next << std::endl;
        }
}

int main()
{
    for (int i = 1; i <= 10; i++)
        std::cout << fib(i) << std::endl;

    fib2(10);
}
