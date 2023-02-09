#include <stdio.h>
#include <string.h>

int isVPS(char str[51]);

int main(void) {
    int iteration;
    char str[51];
    scanf("%d", &iteration);
    for(int i = 0; i < iteration; i++) {
        scanf("%s", str);
        printf(isVPS(str) ? "YES\n" : "NO\n");
    }
    return 0;
}

int isVPS(char str[51]) {
    int len = strlen(str), cnt = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') cnt++;
        else if (str[i] == ')') cnt--;
        if (cnt < 0) return 0;
    }
    if (cnt) return 0;
    return 1;
}