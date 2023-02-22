#include <stdio.h>

int main(void) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d", a + d > b + c ? a + d - b - c : b + c - a - d);
    return 0;
}