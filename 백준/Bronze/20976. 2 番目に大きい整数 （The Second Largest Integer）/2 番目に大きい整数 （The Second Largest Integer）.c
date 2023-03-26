#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d", a < b ? b < c ? b : a < c ? c : a : a < c ? a : b < c ? c : b);
    return 0;
}