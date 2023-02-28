#include <stdio.h>
#include <string.h>

#define MAX 1000001
#define BOOM 37

int main(void) {
    char str[MAX], bomb[BOOM], result[MAX];
    int idx = 0, tmp = 0, len, boom;
    scanf("%s%s", str, bomb);
    len = strlen(str);
    boom = strlen(bomb);
    for (int i = 0; i < len; i++) {
        if (i < boom - 1) result[idx++] = str[i];
        else {
            result[idx++] = str[i];
            while (!strncmp(bomb, result + idx - boom, boom)) idx -= boom;
        }
    }
    result[idx] = '\0';
    if (idx) printf("%s", result);
    else printf("FRULA");
    return 0;
}