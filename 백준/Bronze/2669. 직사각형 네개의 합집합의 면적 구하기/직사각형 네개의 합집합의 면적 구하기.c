#include <stdio.h>

#define MAX 100

int main(void) {
    int arr[MAX][MAX] = {0}, left, bottom, right, top, result = 0;
    for (int i = 0; i < 4; i++) {
        scanf("%d%d%d%d", &left, &bottom, &right, &top);
        for (int j = left; j < right; j++) {
            for (int k = bottom; k < top; k++) {
                if (!arr[j][k]) arr[j][k] = 1;
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) result += arr[i][j];
    }
    printf("%d", result);
    return 0;
}