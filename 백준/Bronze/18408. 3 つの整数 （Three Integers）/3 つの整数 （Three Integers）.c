#include <stdio.h>

int main(void) {
    int one = 0, two = 0, tmp;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &tmp);
        if (tmp == 1)
            one++;
        else
            two++;
    }
    printf("%d", one > two ? 1 : 2);
    return 0;
}