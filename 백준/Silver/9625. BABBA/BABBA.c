#include <stdio.h>

int main(void) {
    int num, A = 1, B = 0, tmp;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        tmp = B;
        B += A;
        A = tmp;
    }
    printf("%d %d", A, B);
    return 0;
}