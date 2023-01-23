#include <stdio.h>
#include <string.h>

void reverseString(char str[]);

int main(void) {
    char a[10002] = {0}, b[10002] = {0}, c[10003] = {0};
    scanf("%s%s", a, b);
    int lenA = strlen(a);
    int lenB = strlen(b);
    int larger;

    // 뒤집은 다음에 일단 더함
    larger = lenA >= lenB ? lenA : lenB;
    reverseString(a);
    reverseString(b);
    for (int i = 0; i < larger; i++) {
        if (i >= lenA) c[i] = b[i];
        else if (i >= lenB) c[i] = a[i];
        else c[i] = a[i] + b[i] - '0';
    }
    c[larger] = '0';

    // 다시 뒤집고 자릿수 올림
    reverseString(c);
    int carry = 0;
    for (int i = larger; i >= 0; i--) {
        c[i] += carry;
        if (c[i] > '9') {
            carry = 1;
            c[i] -= 10;
        } else carry = 0;
    }

    // 앞부분 0 제거
    while (c[0] == '0') {
        for (int i = 0; i < larger; i++) {
            c[i] = c[i + 1];
        }
        c[larger] = '\0';
        larger--;
    }

    printf("%s", c);
    return 0;
}

void reverseString(char str[]) {
    int len = strlen(str);
    char tmp;
    for (int i = 0; i < len / 2; i++) {
        tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}