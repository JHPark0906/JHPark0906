#include <stdio.h>

int main(void) {
    int tmp, sum = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &tmp);
        sum += tmp < 40 ? 40 : tmp;
    }
    printf("%d", sum / 5);
    return 0;
}