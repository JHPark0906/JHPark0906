#include <stdio.h>

int main(void) {
    int input[5], result = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &input[i]);
        result += input[i] * input[i];
    }
    result %= 10;
    printf("%d", result);
    return 0;
}