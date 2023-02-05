#include <stdio.h>
#include <string.h>

int recursion(const char *s, int l, int r, int *cnt);
int isPalindrome(const char *s, int *cnt);

int main(void) {
    int cnt;
    int iteration, result;
    char str[1001];
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%s", str);
        (cnt) = 0;
        result = isPalindrome(str, &cnt);
        printf("%d %d\n", result, cnt);
    }
    return 0;
}

int recursion(const char *s, int l, int r, int *cnt){
    ++(*cnt);
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1, cnt);
}

int isPalindrome(const char *s, int *cnt){
    return recursion(s, 0, strlen(s) - 1, cnt);
}