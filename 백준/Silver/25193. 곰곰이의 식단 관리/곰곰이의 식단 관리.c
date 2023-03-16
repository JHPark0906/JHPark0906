#include <stdio.h>

int main(void) {
    int len, chicken = 0;
    char tmp;
    scanf(" %d", &len);
    for (int i = 0; i < len + 1; i++) {
        scanf("%c", &tmp);
        if (tmp == 'C') chicken++;
    }
    printf("%d", (chicken / (len - chicken + 1)) + (chicken % (len - chicken + 1) ? 1 : 0));
    return 0;
}