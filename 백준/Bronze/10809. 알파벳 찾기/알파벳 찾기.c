#include <stdio.h>
#include <string.h>

int main(void) {
    char input[101];
    int alphabet[26];
    int len;
    scanf("%s", input);
    len = strlen(input);
    for (int i = 0; i < 26; i++) alphabet[i] = -1;
    for (int i = 0; i < len; i++) {
        if (alphabet[input[i] - 97] == -1) alphabet[input[i] - 97] = i;
    }
    for (int i = 0; i < 25; i++) {
        printf("%d ", alphabet[i]);
    }
    printf("%d", alphabet[25]);
    return 0;
}