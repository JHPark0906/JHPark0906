#include <stdio.h>

int main(void) {
    int background[100][100] = {0};
    int result = 0;
    int blackPaper;
    scanf("%d", &blackPaper);
    int x, y;
    for (int i = 0; i < blackPaper; i++) {
        scanf("%d%d", &x, &y);
        for (int j = 0; j < 100; j++) {
            background[x + j / 10][y + j % 10] = 1;
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (background[i][j]) result++;
        }
    }
    printf("%d", result);
    return 0;
}