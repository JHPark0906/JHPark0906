#include <stdio.h>

#define MAX 91

int main(void) {
    int len;
    long long arr[MAX][2] = {0};
    scanf("%d", &len);
    arr[1][1] = 1;
    for (int i = 2; i <= len; i++) {
        arr[i][1] = arr[i - 1][0];
        arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
    }
    printf("%lld", arr[len][0] + arr[len][1]);
    return 0;
}