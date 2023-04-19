#include <stdio.h>
#include <limits.h>

#define ARR_MAX 100000

int getMax(int a, int b, int c);
int getMin(int a, int b, int c);

int main(void) {
    int length, arr[ARR_MAX][3] = {0}, max[2][3] = {0}, min[2][3] = {0};
    scanf("%d", &length);
    for (int i = 0; i < length; i++)
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);

    for (int i = 0; i < 3; i++) {
        max[(length - 1) % 2][i] = arr[length - 1][i];
        min[(length - 1) % 2][i] = arr[length - 1][i];
    }

    for (int i = length - 2; i >= 0; i--) {
        int j = i % 2; int k = (j + 1) % 2;
        max[j][0] = arr[i][0] + getMax(max[k][0], max[k][1], INT_MIN);
        max[j][1] = arr[i][1] + getMax(max[k][0], max[k][1], max[k][2]);
        max[j][2] = arr[i][2] + getMax(INT_MIN, max[k][1], max[k][2]);
        min[j][0] = arr[i][0] + getMin(min[k][0], min[k][1], INT_MAX);
        min[j][1] = arr[i][1] + getMin(min[k][0], min[k][1], min[k][2]);
        min[j][2] = arr[i][2] + getMin(INT_MAX, min[k][1], min[k][2]);
    }

    printf("%d %d", getMax(max[0][0], max[0][1], max[0][2]), getMin(min[0][0], min[0][1], min[0][2]));
    return 0;
}

int getMax(int a, int b, int c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int getMin(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}