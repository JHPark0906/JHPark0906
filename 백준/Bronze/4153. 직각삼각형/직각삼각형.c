#include <stdio.h>

int main(void) {
    int a, b, c, longest;
    while (1) {
        scanf("%d%d%d", &a, &b, &c);
        if (!a && !b && !c) break;
        a *= a;
        b *= b;
        c *= c;
        longest = a < b ? (b < c ? c : b) : (a < c ? c : a);
        printf("%s\n", a + b + c == 2 * longest ? "right" : "wrong");
    }
    return 0;
}