#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int row, column;
    scanf("%d%d", &row, &column);
    int **mat1 = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++) {
        mat1[i] = (int *)malloc(sizeof(int) * column);
    }
    int **mat2 = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++) {
        mat2[i] = (int *)malloc(sizeof(int) * column);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            scanf("%d", &mat2[i][j]);
            printf("%d ", mat1[i][j] + mat2[i][j]);
        }
        printf("\n");
    }
    
    free(mat1);
    free(mat2);
    return 0;
}