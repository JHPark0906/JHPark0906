#include <stdio.h>

#define MAX 100001

int main(void) {
    int size, iteration, arr[MAX], sum[MAX + 1] = {0}, a, b;
    scanf("%d%d", &size, &iteration);
    scanf("%d", &arr[0]);
    sum[1] = arr[0];
    for (int i = 1; i < size; i++) {
        scanf("%d", &arr[i]);
        sum[i + 1] = sum[i] + arr[i];
    }
    for (int i = 0; i < iteration; i++) {
        scanf("%d%d", &a, &b);
        printf("%d\n", sum[b] - sum[a - 1]);
    }
    return 0;
}