#include <stdio.h>

#define MAX 10000001
#define DIVISOR 10

int arr[MAX][2];

int main(void) {
    int num;
    scanf("%d", &num);
    arr[1][0] = 1;
    for (int i = 2; i <= num; i++) {
        arr[i][0] = (arr[i - 1][0] + arr[i - 1][1]) % DIVISOR;
        arr[i][1] = arr[i - 1][0];
    }
    printf("%d", (arr[num][0] + arr[num][1]) % DIVISOR);
    return 0;
}