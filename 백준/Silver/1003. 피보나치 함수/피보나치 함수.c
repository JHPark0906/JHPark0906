#include <stdio.h>

#define MAX 41

int fib[MAX] = {0};

void fillFib();
int getFib(int num);

int main(void) {
    int iteration, num;
    scanf("%d", &iteration);
    fillFib();
    for (int i = 0; i < iteration; i++) {
        scanf("%d", &num);
        printf("%d %d\n", getFib(num - 1), getFib(num));
    }
    return 0;
}

void fillFib() {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int getFib(int num) {
    if (num == -1) return 1;
    return fib[num];
}