#include <stdio.h>

int main(void) {
    int repetition, a, b;
    scanf("%d", &repetition);
    for (int i = 0; i < repetition; i++) {
        scanf("%d%d", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i + 1, a, b, a + b);
    }
    return 0;
}