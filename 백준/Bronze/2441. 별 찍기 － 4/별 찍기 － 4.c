#include <stdio.h>

int main(void) {
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j < i) printf(" ");
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}