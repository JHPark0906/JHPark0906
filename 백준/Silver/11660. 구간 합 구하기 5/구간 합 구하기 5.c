#include <stdio.h>

#define MAX 1024

int main(void) {
    int size, iteration, arr[MAX][MAX], tmp[MAX][MAX + 1] = {0}, sum[MAX + 1][MAX + 1] = {0}, left, top, right, bottom;
    scanf("%d%d", &size, &iteration);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &arr[i][j]);
            tmp[i][j + 1] = tmp[i][j] + arr[i][j];
            sum[i + 1][j + 1] = sum[i][j + 1] + tmp[i][j + 1];
        }
    }
    for (int i = 0; i < iteration; i++) {
        scanf("%d%d%d%d", &left, &top, &right, &bottom);
        left--; top--;
        printf("%d\n", sum[right][bottom] - sum[right][top] - sum[left][bottom] + sum[left][top]);
    }
    return 0;
}