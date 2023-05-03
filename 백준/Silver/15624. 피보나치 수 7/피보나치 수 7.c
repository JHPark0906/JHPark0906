#include <stdio.h>

#define MAX 1000001
#define DIVISOR 1000000007

int fib[MAX];

int main(void) {
    int num;
    scanf("%d", &num);
    fib[0] = 0; fib[1] = 1; fib[2] = 1;
    for (int i = 3; i <= num; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % DIVISOR;
    }
    printf("%d", fib[num]);
    return 0;
}