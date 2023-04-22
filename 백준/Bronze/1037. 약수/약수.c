#include <stdio.h>

int main(void) {
    int num, tmp, min, max;
    scanf("%d", &num);
    scanf("%d", &tmp);
    min = tmp;
    max = tmp;
    for (int i = 1; i < num; i++) {
        scanf("%d", &tmp);
        min = tmp < min ? tmp : min;
        max = tmp > max ? tmp : max;
    }
    printf("%d", min * max);
    return 0;
}