#include <stdio.h>

#define MAX 1516
#define DIVISOR 1000000007

int arr[MAX][3];

int main(void) {
    int num;
    scanf("%d", &num);
    arr[1][1] = 1; arr[1][2] = 1;
    for (int i = 2; i <= num; i++) {
        arr[i][0] = (arr[i - 1][1] + arr[i - 1][2]) % DIVISOR;
        arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % DIVISOR;
        arr[i][2] = (arr[i - 1][0] + arr[i - 1][1]) % DIVISOR;
    }
    printf("%d", arr[num - 1][1]);
    return 0;
}