#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    printf(m <= 2 ? "NEWBIE!" : m <= n ? "OLDBIE!" : "TLE!");
    return 0;
}