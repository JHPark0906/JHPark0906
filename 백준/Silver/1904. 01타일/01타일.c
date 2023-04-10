#include <stdio.h>

#define MAX 1000001
#define DIVISOR 15746

long long arr[MAX];

int main(void) {
    int num;
    scanf("%d", &num);
    arr[1] = 1; arr[2] = 2;
    for (int i = 3; i <= num; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % DIVISOR;
    printf("%lld", arr[num]);
    return 0;
}