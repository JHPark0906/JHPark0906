#include <stdio.h>

int isPrime(int n);

int main(void) {
    int input, result;
    while (1) {
        result = 0;
        scanf("%d", &input);
        if (!input) break;
        for (int i = input + 1; i <= 2 * input; i++) {
            if (isPrime(i)) result++;
        }
        printf("%d\n", result);
    }
    return 0;
}

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    int output = 1;
    for (int i = 2; i <= n; i++) {
        if (i * i > n) break;
        if (!(n % i)) {
            output = 0;
            break;
        }
    }
    return output;
}