#include <stdio.h>

int main(void) {
    int height, up, down;
    scanf("%d%d%d", &up, &down, &height);
    printf("%d", (height - up) % (up - down) ?
                 (height - up) / (up - down) + 2 :
                 (height - up) / (up - down) + 1);
    return 0;
}