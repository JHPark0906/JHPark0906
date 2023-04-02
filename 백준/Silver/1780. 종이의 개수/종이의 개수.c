#include <stdio.h>
#include <stdbool.h>

#define MAX 2187

void countArea(int arr[MAX][MAX], int size, int left, int top, int result[3]);
bool isAllSameNumber(int arr[MAX][MAX], int size, int left, int top);

int main(void) {
    int size, arr[MAX][MAX];
    int result[3] = {0};
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &arr[i][j]);
    countArea(arr, size, 0, 0, result);
    printf("%d\n%d\n%d", result[0], result[1], result[2]);
    return 0;
}

void countArea(int arr[MAX][MAX], int size, int left, int top, int result[3]) {
    if (size == 1 || isAllSameNumber(arr, size, left, top)) result[arr[left][top] + 1]++;
    else {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                countArea(arr, size / 3, left + i * (size / 3), top + j * (size / 3), result);
    }
}

bool isAllSameNumber(int arr[MAX][MAX], int size, int left, int top) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (arr[left + i][top + j] != arr[left][top])
                return false;
    return true;
}