#include <stdio.h>

int main(void) {
    int s, a, b;
    scanf("%d%d%d", &s, &a, &b);
    printf("%d", s <= a ? 250 : 250 + ((s - a) / b + ((s - a) % b ? 1 : 0)) * 100);
    return 0;
}