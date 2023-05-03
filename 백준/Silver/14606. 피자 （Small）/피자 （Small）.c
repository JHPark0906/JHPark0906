#include <stdio.h>

#define MAX 11

int main(void) {
    int height, happy[MAX];
    scanf("%d", &height);
    happy[0] = 0; happy[1] = 0;

    for (int i = 2; i <= height; i++) {
        if (i % 2) {
            happy[i] = (i / 2) * (i / 2 + 1) + happy[i / 2] + happy[i / 2 + 1];
        } else {
            happy[i] = (i / 2) * (i / 2) + 2 * happy[i / 2];
        }
    }

    printf("%d", happy[height]);
    return 0;
}