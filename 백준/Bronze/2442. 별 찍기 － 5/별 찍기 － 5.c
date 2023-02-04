#include <stdio.h>

int main(void) {
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + size; j++) {
            if (j < size - i - 1) printf(" ");
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}