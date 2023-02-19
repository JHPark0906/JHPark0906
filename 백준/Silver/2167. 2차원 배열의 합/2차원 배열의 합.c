#include <stdio.h>

int main(void) {
    int row, col, iteration, result, startR, startC, endR, endC;
    scanf("%d%d", &row, &col);
    int arr[300][300];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        result = 0;
        scanf("%d%d%d%d", &startR, &startC, &endR, &endC);
        for (int j = startR - 1; j < endR; j++) {
            for (int k = startC - 1; k < endC; k++) {
                result += arr[j][k];
            }
        }
        printf("%d\n", result);
    }
    return 0;
}