#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    while(a && b) {
        printf(a > b ? "Yes\n" : "No\n");
        scanf("%d%d", &a, &b);
    }
    return 0;
}