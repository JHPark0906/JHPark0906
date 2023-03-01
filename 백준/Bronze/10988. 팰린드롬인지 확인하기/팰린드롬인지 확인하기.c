#include <stdio.h>
#include <string.h>

#define MAX 101

int isPalindrome(char str[]);

int main(void) {
    char str[MAX];
    scanf("%s", str);
    printf("%d", isPalindrome(str));
    return 0;
}

int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) if (str[i] != str[len - i - 1]) return 0;
    return 1;
}