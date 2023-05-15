#include <stdio.h>
#include <string.h>

#define MAX 101

int main(void) {
    char str[MAX];
    scanf("%s", str);
    printf("%d", (int)strlen(str));
    return 0;
}