#include <stdio.h>

int main(void) {
    int size;
    scanf("%d", &size);
    for (int i = size; i > 0; i--) {
        for (int j = 0; j < i; j++) printf("*");
        printf("\n");
    }
    return 0;
}