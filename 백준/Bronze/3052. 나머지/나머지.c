#include <stdio.h>

int main(void) {
    int input[10];
    int remainder[42] = {0};
    int result = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &input[i]);
        remainder[input[i] % 42]++;
    }
    for (int i = 0; i < 42; i++) {
        if (remainder[i]) result++;
    }
    printf("%d", result);
    return 0;
}