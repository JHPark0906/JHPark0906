#include <stdio.h>

int main(void) {
    int size;
    scanf("%d", &size);
    for(int i = 1; i <= size; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}