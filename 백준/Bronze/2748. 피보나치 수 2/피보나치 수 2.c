#include <stdio.h>

int main(void) {
    long long fib[91];
    int num;
    fib[0] = 0;
    fib[1] = 1;
    scanf("%d", &num);
    for (int i = 2; i <= num; i++) fib[i] = fib[i - 1] + fib[i - 2];
    printf("%lld", fib[num]);
    return 0;
}