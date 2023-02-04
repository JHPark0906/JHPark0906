#include <stdio.h>

int main(void) {
    char tmp;
    int vowel = 0;
    scanf("%c", &tmp);
    while (tmp != '#') {
        if (tmp == 'A' || tmp == 'a' ||
        tmp == 'E' || tmp == 'e' ||
        tmp == 'I' || tmp == 'i' ||
        tmp == 'O' || tmp == 'o' ||
        tmp == 'U' || tmp == 'u') vowel++;
        else if(tmp == '\n') {
            printf("%d\n", vowel);
            vowel = 0;
        }
        scanf("%c", &tmp);
    }
    return 0;
}