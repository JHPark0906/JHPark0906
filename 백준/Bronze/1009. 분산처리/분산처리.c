#include <stdio.h>

int main(void) {
    int input, a, b, result;
    scanf("%d", &input);
    for (int i = 0; i < input; i++) {
        scanf("%d%d", &a, &b);
        result = a % 10;
        for (int j = 1; j < b; j++) {
            result = (result * a) % 10;
        }
        if (!result) result = 10;
        printf("%d\n", result);
    }
    return 0;
}