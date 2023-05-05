#include <stdio.h>

#define MAX 50001
#define DIVISOR 1000000009

int main(void) {
    int num, arr[MAX][2] = {0};
    scanf("%d", &num);
    arr[1][0] = 1; arr[2][0] = 1;
    arr[3][0] = 1; arr[3][1] = 1;
    for (int i = 4; i <= num; i++) {
        arr[i][0] = (arr[i - 1][0] + arr[i - 1][1]) % DIVISOR;
        arr[i][1] = (arr[i - 2][0]) % DIVISOR;
    }
    printf("%d", (arr[num][0] + arr[num][1]) % DIVISOR);
    return 0;
}