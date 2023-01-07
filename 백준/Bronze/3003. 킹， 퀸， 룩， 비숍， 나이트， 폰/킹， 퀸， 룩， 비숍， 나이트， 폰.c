#include <stdio.h>

int main(void) {
    int input[6], chess[6] = {1, 1, 2, 2, 2, 8};
    for (int i = 0; i < 6; i++) scanf("%d", &input[i]);
    for (int i = 0; i < 5; i++) printf("%d ",chess[i] - input[i]);
    printf("%d", chess[5] - input[5]);
    return 0;
}