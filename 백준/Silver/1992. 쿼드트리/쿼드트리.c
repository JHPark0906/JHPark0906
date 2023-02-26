#include <stdio.h>

void print(int arr[64][64], int left, int top, int right, int bottom);
int isOneColored(int arr[64][64], int left, int top, int right, int bottom);

int main(void) {
    int arr[64][64], size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) scanf("%1d", &arr[i][j]);
    }
    print(arr, 0, 0, size - 1, size - 1);
    return 0;
}

void print(int arr[64][64], int left, int top, int right, int bottom) {
    if (isOneColored(arr, left, top, right, bottom)) printf("%d", arr[left][top]);
    else {
        int newX = (left + right) / 2, newY = (top + bottom) / 2;
        printf("(");
        print(arr, left, top, newX, newY);
        print(arr, left, newY + 1, newX, bottom);
        print(arr, newX + 1, top, right, newY);
        print(arr, newX + 1, newY + 1, right, bottom);
        printf(")");
    }
}

int isOneColored(int arr[64][64], int left, int top, int right, int bottom) {
    for (int i = left; i <= right; i++) {
        for (int j = top; j <= bottom; j++) if (arr[i][j] != arr[left][top]) return 0;
    }
    return 1;
}