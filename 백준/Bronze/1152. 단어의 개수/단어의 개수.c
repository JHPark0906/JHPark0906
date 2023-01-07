#include <stdio.h>
#include <string.h>

int main(void) {
    char input[1000001];
    int space = 0, len;
    scanf("%[^\n]s", input);
    len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] == ' ' && i != 0 && i != len - 1) space++;
    }
    if (len == 1 && input[0] == ' ') space = -1;
    printf("%d", ++space);
    return 0;
}