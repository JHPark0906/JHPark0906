#include <stdio.h>

int main(void) {
    int a, b, c, d, sum;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    sum = a + b + c + d;
    printf("%d\n%d", sum / 60, sum % 60);
    return 0;
}