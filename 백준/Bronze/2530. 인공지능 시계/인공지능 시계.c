#include <stdio.h>

int main(void) {
    int h, m, s, time;
    scanf("%d%d%d%d", &h, &m, &s, &time);

    s += time;
    m += s / 60; s %= 60;
    h += m / 60; m %= 60;
    h %= 24;

    printf("%d %d %d", h, m, s);

    return 0;
}