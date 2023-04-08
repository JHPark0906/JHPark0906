#include <stdio.h>

#define MAX 1000001
#define BILLION 1000000000

int fib[MAX] = {0};

int getSign(int n);
int getFib(int n);

int main(void) {
    fib[0] = 0;
    fib[1] = 1;
    int num;
    scanf("%d", &num);
    printf("%d\n%d", getSign(num), getFib(num));
    return 0;
}

int getSign(int n) {
    if (n == 0) return 0;
    if (n < 0 && n % 2 == 0) return -1;
    return 1;
}

int getFib(int n) {
    n *= (n < 0 ? -1 : 1);
    if (n <= 1) return n;
    if (fib[n] == 0) fib[n] = getFib(n - 1) + getFib(n - 2);
    while(fib[n] >= BILLION) fib[n] -= BILLION;
    return fib[n];
}