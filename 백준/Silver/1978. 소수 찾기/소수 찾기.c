#include <stdio.h>

int isPrime(int n);

int main(void) {
    int input;
    scanf("%d", &input);
    int num, result = 0;
    for (int i = 0; i < input; i++) {
        scanf("%d", &num);
        if (isPrime(num)) result++;
    }
    printf("%d", result);
    return 0;
}

int isPrime(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    for (int i = 2; i < n; i++) {
        if (i * i > n) break;
        if (!(n % i)) return 0;
    }
    return 1;
}