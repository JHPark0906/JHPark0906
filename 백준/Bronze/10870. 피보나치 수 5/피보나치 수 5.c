#include <stdio.h>

int fib(int num);

int main(void) {
    int num;
    scanf("%d", &num);
    printf("%d", fib(num));
    return 0;
}

int fib(int num) {
    if (num <= 0) return 0;
    else if (num <= 2) return 1;
    return fib(num - 1) + fib(num - 2);
}