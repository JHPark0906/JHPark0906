#include <stdio.h>

int main() {
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(j < (size - i - 1) ? " " : "*");
        }
        if (i != size) printf("\n");
    }
    return 0;
}