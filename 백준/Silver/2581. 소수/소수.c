#include <stdio.h>

int isPrime(int n);

int main(void) {
    int start, end;
    scanf("%d%d", &start, &end);
    int min = end, sum = 0, check = 0;
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            check++;
            if (min > i) min = i;
            sum += i;
        }
    }
    if (!check) {
        printf("-1");
        return 0;
    }
    printf("%d\n%d", sum, min);
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