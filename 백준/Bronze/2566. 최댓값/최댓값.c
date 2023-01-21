#include <stdio.h>

int main(void) {
    int arr[9][9];
    int max = -1, idx = -1;
    for (int i = 0; i < 81; i++) {
        scanf("%d", &arr[i / 9][i % 9]);
        if (max < arr[i / 9][i % 9]) {
            max = arr[i / 9][i % 9];
            idx = i;
        }
    }
    printf("%d\n%d %d", max, idx / 9 + 1, idx % 9 + 1);
    return 0;
}