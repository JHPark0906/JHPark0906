#include <stdio.h>

int isPrime(int n, int prime[], int *size);

int main(void) {
    int start, end;
    int size = 0;
    int prime[1000000];
    scanf("%d%d", &start, &end);
    prime[0] = 2; size++;
    if (start <= 2) {
        if (end >= 3) {
            printf("2\n");
            start = 3;
        }
        else if (end == 2) {
            printf("2");
            return 0;
        }
        else return 0;
    }

    for (int i = 3; i < start; i++) {
        isPrime(i, prime, &size);
    }

    for (int i = start; i <= end; i++) {
        if (isPrime(i, prime, &size)) printf("%d\n", i);
    }

    return 0;
}

int isPrime(int n, int prime[], int *size) {
    int result = 1;
    if (n == 1) return 0;
    for (int i = 0; i < *size; i++) {
        if (prime[i] * prime[i] > n) break;
        if (!(n % prime[i])) {
            result = 0;
            break;
        }
    }
    if (result) {
        prime[*size] = n;
        (*size)++;
    }
    return result;
}