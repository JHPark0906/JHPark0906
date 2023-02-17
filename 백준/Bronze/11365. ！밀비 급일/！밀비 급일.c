#include <stdio.h>
#include <string.h>

int main(void) {
    char str[502];
    int len;
    while (fgets(str, 502, stdin)) {
        if (!strcmp(str, "END\n")) break;
        len = strlen(str);
        for (int i = len - 2; i >= 0; i--)
            printf("%c", str[i]);
        printf("\n");
    }
    return 0;
}