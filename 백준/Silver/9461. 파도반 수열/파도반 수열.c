#include <stdio.h>

#define MAX 101

long long arr[MAX] = {0};

long long getLength(int n);

int main(void) {
    int input, num;
    arr[1] = 1; arr[2] = 1; arr[3] = 1; arr[4] = 2; arr[5] = 2;
    scanf("%d", &input);
    for (int i = 0; i < input; i++) {
        scanf("%d", &num);
        printf("%lld\n", getLength(num));
    }
    return 0;
}

long long getLength(int n) {
    if (!arr[n]) arr[n] = getLength(n - 1) + getLength(n - 5);
    return arr[n];
}