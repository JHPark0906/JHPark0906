#include <stdio.h>

int main(void) {
    int input[9];
    int max = 0, idx = 0;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &input[i]);
        if (input[i] > max) {
            max = input[i];
            idx = i;
        }
    }
    printf("%d\n%d", max, idx + 1);
    return 0;
}