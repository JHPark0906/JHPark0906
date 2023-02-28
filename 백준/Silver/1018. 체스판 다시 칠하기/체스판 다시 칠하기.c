#include <stdio.h>

#define MAX 50

int getColoringTimes(char board[MAX][MAX], int left, int top);

int main(void) {
    int row, col, min = -1, tmp;
    char board[MAX][MAX];
    scanf("%d%d", &row, &col);
    for (int i = 0; i < row; i++) scanf("%s", board[i]);
    for (int i = 0; i <= row - 8; i++) {
        for (int j = 0; j <= col - 8; j++) {
            tmp = getColoringTimes(board, i, j);
            if (min == -1 || tmp < min) min = tmp;
        }
    }
    printf("%d", min);
    return 0;
}

int getColoringTimes(char board[MAX][MAX], int left, int top) {
    int result = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2) {
                if (board[left + i][top + j] == board[left][top]) result++;
            } else {
                if (board[left + i][top + j] != board[left][top]) result++;
            }
        }
    }
    if (result > 32) result = 64 - result;
    return result;
}