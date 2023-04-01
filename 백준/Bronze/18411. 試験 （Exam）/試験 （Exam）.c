#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d", a < b ? a < c ? b + c : a + b : b < c ? a + c : a + b);
    return 0;
}