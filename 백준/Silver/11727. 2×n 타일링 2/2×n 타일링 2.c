#include <stdio.h>

#define MAX 1001
#define DIVISOR 10007

int main(void) {
    int length, arr[MAX];
    arr[0] = 0; arr[1] = 1; arr[2] = 3;
    scanf("%d", &length);
    for (int i = 3; i <= length; i++)
        arr[i] = (arr[i - 1] + 2 * arr[i - 2]) % DIVISOR;
    printf("%d", arr[length]);
    return 0;
}