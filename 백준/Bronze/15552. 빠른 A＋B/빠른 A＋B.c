#include <stdio.h>

int main(void) {
    int input;
    scanf("%d", &input);
    int a, b;
    for (int i = 0; i < input; i++) {
        scanf("%d%d", &a, &b);
        printf("%d\n", a + b);
    }
    return 0;
}