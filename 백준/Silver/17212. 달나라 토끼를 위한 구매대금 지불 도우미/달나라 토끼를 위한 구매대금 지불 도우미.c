#include <stdio.h>

#define MAX 100001

int getMinimum(int a, int b, int c, int d);

int main(void) {
    int num, arr[MAX] = {0};
    scanf("%d", &num);
    arr[1] = 1; arr[2] = 1; arr[3] = 2; arr[4] = 2; arr[5] = 1; arr[6] = 2; arr[7] = 1;
    for (int i = 8; i <= num; i++) {
        arr[i] = 1 + getMinimum(arr[i - 7], arr[i - 5], arr[i - 2], arr[i - 1]);
    }
    printf("%d", arr[num]);
    return 0;
}

int getMinimum(int a, int b, int c, int d) {
    return (a < b ? (a < c ? (a < d ? a : d) : (c < d ? c : d)) : (b < c ? (b < d ? b : d) : (c < d ? c : d)));
}