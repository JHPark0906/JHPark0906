#include <stdio.h>

int star(int n, int size);

int main(void) {
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size * size; i++) {
        printf(star(i, size) ? "*" : " ");
        if (i % size == size - 1) printf("\n");
    }
    return 0;
}

int star(int n, int size) {
    int x = n % size;
    int y = n / size;
    int partSize = size / 3;
    if (x / partSize == 1 && y / partSize == 1) return 0;
    if (partSize == 1 && n != 4) return 1;
    else {
        return star(x % partSize + y % partSize * partSize, partSize);
    }
}