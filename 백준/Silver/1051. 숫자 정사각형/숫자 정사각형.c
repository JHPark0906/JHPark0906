#include <stdio.h>
#include <stdbool.h>

#define ARR_MAX 50

int arr[ARR_MAX][ARR_MAX], row, col, min;

bool findSquare(int length);
bool isAllSame(int left, int top, int length);

int main(void) {
    scanf("%d%d", &row, &col);
    min = row < col ? row : col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%1d", &arr[i][j]);
    for (int i = min; i > 0; i--) {
        if (findSquare(i)) {
            printf("%d", i * i);
            break;
        }
    }
    return 0;
}

bool findSquare(int length) {
   if (length <= 1) return true;
    for (int i = 0; i <= row - length; i++)
        for (int j = 0; j <= col - length; j++)
            if (isAllSame(i, j, length))
                return true;
    return false;
}

bool isAllSame(int left, int top, int length) {
    int x = arr[left][top], right = left + length - 1, bottom = top + length - 1;
    if (x == arr[right][top] && x == arr[right][bottom] && x == arr[left][bottom])
        return true;
    return false;
}