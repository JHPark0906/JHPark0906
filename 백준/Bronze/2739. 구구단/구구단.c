#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < 8; i++) printf("%d * %d = %d\n", num, i + 1, num * (i + 1));
    printf("%d * 9 = %d", num, num * 9);
    return 0;
}