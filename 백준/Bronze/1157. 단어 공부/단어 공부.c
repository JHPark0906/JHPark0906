#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char input[1000001];
    scanf("%s", input);
    int len = strlen(input);
    int alphabet[26] = {0};
    for (int i = 0; i < len; i++) {
        alphabet[toupper(input[i]) - 65]++;
    }
    int max = 0;
    int check = 0;
    int result;
    for (int i = 0; i < 26; i++) {
        if (max < alphabet[i]) {
            max = alphabet[i];
            result = toupper(input[i]);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (max == alphabet[i]) {
            check++;
            result = i + 65;
        }
    }
    if (check == 1) printf("%c", result);
    else printf("?");
    return 0;
}