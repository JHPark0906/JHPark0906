#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int test;
    scanf("%d", &test);
    int *arr = (int *) malloc(sizeof(int) * 2 * test);
    for (int i = 0; i < test * 2; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < test; i++) {
        printf("%d\n", arr[2 * i] + arr[2 * i + 1]);
    }
    return 0;
}