#include <stdio.h>

int main(void) {
    int iteration, a, b;
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a / b + (a % b ? 1 : 0));
    }
    return 0;
}