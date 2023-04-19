#include <stdio.h>

#define ARR_MAX 100001
#define DIVISOR 1000000009

int filled, arr[ARR_MAX][3];

void fillArray(int num);

int main(void) {
    int iteration, num;
    scanf("%d", &iteration);
    arr[1][0] = 1; arr[2][1] = 1; arr[3][0] = 1; arr[3][1] = 1; arr[3][2] = 1;
    filled = 3;

    for (int i = 0; i < iteration; i++) {
        scanf("%d", &num);
        fillArray(num);
        printf("%d\n", ((arr[num][0] + arr[num][1]) % DIVISOR + arr[num][2]) % DIVISOR);
    }

    return 0;
}

void fillArray(int num) {
    if (num <= filled) return;
    for (int i = filled + 1; i <= num; i++) {
        arr[i][0] = (arr[i - 1][1] + arr[i - 1][2]) % DIVISOR;
        arr[i][1] = (arr[i - 2][0] + arr[i - 2][2]) % DIVISOR;
        arr[i][2] = (arr[i - 3][0] + arr[i - 3][1]) % DIVISOR;
    }
}