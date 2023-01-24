#include <stdio.h>

int main(void) {
    int repetition;
    scanf("%d", &repetition);
    int a, b;
    for (int i = 0; i < repetition; i++) {
        scanf("%d%d", &a, &b);
        printf("Case #%d: %d\n", i + 1, a + b);
    }
    return 0;
}