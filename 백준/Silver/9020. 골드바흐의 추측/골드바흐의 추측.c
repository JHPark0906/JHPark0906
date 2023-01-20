#include <stdio.h>

int isPrime(int n);

int main(void) {
    int iteration;
    scanf("%d", &iteration);
    int num;
    for (int i = 0; i < iteration; i++) {
        scanf("%d", &num);
        for (int j = num / 2; j >= 0; j--) {
            if (isPrime(num - j) && isPrime(j)) {
                printf("%d %d\n", j, num - j);
                break;
            }
        }
    }
    return 0;
}

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    for (int i = 2; i < n; i++) {
        if (!(n % i)) return 0;
    }
    return 1;
}