#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", a + 7 * b <= 30);
    return 0;
}