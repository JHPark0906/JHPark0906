#include <stdio.h>

int main(void) {
    long long result = 0, tmp;
    for (int i = 0; i < 3; i++) {
        scanf("%lld", &tmp);
        result += tmp;
    }
    printf("%lld", result);
    return 0;
}