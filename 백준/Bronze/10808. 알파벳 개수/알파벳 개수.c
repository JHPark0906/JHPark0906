#include <stdio.h>
#include <string.h>

#define STR_MAX 101

int main(void) {
    char str[STR_MAX];
    int alphabet[26] = {0};
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {
        alphabet[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        printf("%d ", alphabet[i]);
    return 0;
}