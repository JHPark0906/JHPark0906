#include <stdio.h>

int main(void) {
    int len;
    scanf("%d", &len);
    char input[101];
    scanf("%s", input);
    int result = 0;
    for (int i = 0; i < len; i++) {
        result += input[i] - '0';
    }
    printf("%d", result);
    return 0;
}