#include <stdio.h>

int main(void) {
    int iteration, a, b;
    scanf("%d", &iteration);
    for (int i = 1; i <= iteration; i++) {
        scanf("%d%d", &a, &b);
        printf("Case %d: %d\n", i, a + b);
    }
    return 0;
}