#include <stdio.h>

#define SIZE_MAX 500

int main(void) {
    int size, triangle[SIZE_MAX][SIZE_MAX] = {0}, max[SIZE_MAX][SIZE_MAX] = {0};
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j <= i; j++)
            scanf("%d", &triangle[i][j]);

    for (int j = 0; j < size; j++) {
        max[size - 1][j] = triangle[size - 1][j];
    }
    for (int i = size - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            max[i][j] = triangle[i][j] + (max[i + 1][j] > max[i + 1][j + 1] ? max[i + 1][j] : max[i + 1][j + 1]);

    printf("%d", max[0][0]);
    return 0;
}