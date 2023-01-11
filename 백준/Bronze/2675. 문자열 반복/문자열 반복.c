#include <stdio.h>
#include <string.h>

int main(void) {
    int test;
    int num;
    char str[21];
    int length;
    scanf("%d", &test);
    for (int i = 0; i < test; i++) {
        scanf("%d%s", &num, str);
        length = strlen(str);
        for (int j = 0; j < length; j++) {
            for (int k = 0; k < num; k++) {
                printf("%c", str[j]);
            }
        }
        printf("\n");
    }
    return 0;
}