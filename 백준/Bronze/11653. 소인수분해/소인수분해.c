#include <stdio.h>
#include <stdlib.h>

int isPrime(int prime[], int *num, int n);
int divider(int prime[], int *num, int *input);

int main(void) {
    int input;
    int *prime = (int *)malloc(sizeof(int) * 2);
    if (prime == NULL) {
        printf("Error");
        exit(-1);
    }
    int num = 1, size = 2;
    prime[0] = 2;
    scanf("%d", &input);

    int i = 3;
    while (i <= input) {
        if (isPrime(prime, &num, i)) {
            prime[num] = i;
            (num)++;
        }
        if (num == size) {
            (size) *= 2;
            prime = (int *)realloc(prime, sizeof(int) * size);
            if (prime == NULL) {
                printf("Error");
                exit(-1);
            }
        }
        i++;
    }

    while (input > 1) {
        printf("%d\n", divider(prime, &num, &input));
    }
    free(prime);
    return 0;
}

int isPrime(int prime[], int *num, int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    for (int i = 0; i < *num; i++) {
        if (prime[i] * prime[i] > n) break;
        if (!(n % prime[i])) return 0;
    }
    return 1;
}

int divider(int prime[], int *num, int *input) {
    int result = *input;
    for (int i = 0; i < *num; i++) {
        if (prime[i] > *input) break;
        if (!(*input % prime[i])) {
            result = prime[i];
            (*input) /= prime[i];
            break;
        }
    }
    return result;
}