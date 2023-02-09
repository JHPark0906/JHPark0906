#include <stdio.h>

int main(void) {
    int iteration, stack[100000], idx = 0, tmp, result = 0;
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%d", &tmp);
        if (!tmp) {
            result -= stack[--idx];
        } else {
            stack[idx] = tmp;
            result += stack[idx++];
        }
    }
    printf("%d", result);
    return 0;
}