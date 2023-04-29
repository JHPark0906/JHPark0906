#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    a += b;
    b = a - 2 * b;
    printf("%d\n%d", a > b ? a : b, a < b ? a : b);
    return 0;
}