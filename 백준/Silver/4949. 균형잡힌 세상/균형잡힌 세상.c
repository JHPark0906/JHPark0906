#include <stdio.h>
#include <string.h>

int isBalanced(char str[101]);

int main(void) {
    char str[101];
    while (fgets(str, 102, stdin)) {
        if (strlen(str) == 2 && str[0] == '.' && str[1] == '\n') break;
        str[strlen(str) - 1] = '\0';
        printf(isBalanced(str) ? "yes\n" : "no\n");
    }
    return 0;
}

int isBalanced(char str[101]) {
    int len = strlen(str), idx = 0;
    int bracket[101] = {0};
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') bracket[idx++] = 1;
        else if (str[i] == '[') bracket[idx++] = 2;
        else if (str[i] == ')') {
            if (!idx || bracket[idx - 1] != 1) return 0;
            else idx--;
        } else if (str[i] == ']') {
            if (!idx || bracket[idx - 1] != 2) return 0;
            else idx--;
        }
    }
    if (idx) return 0;
    return 1;
}