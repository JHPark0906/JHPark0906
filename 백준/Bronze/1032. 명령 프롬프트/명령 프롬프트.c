#include <stdio.h>
#include <string.h>

int main(void) {
    char result[51], tmp[51];
    int input, len;
    scanf("%d", &input);
    for (int i = 0; i < input; i++) {
        scanf("%s", tmp);
        if (!i) {
            strcpy(result, tmp);
            len = strlen(result);
        }
        else {
            for (int j = 0; j < len; j++) {
                if (result[j] != tmp[j]) result[j] = '?';
            }
        }
    }
    printf("%s", result);
    return 0;
}