#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int comp(const void *a, const void *b);

int main(void) {
    int input;
    scanf("%d", &input);
    int len = (int)log10(input) + 1;
    int *arr = (int *)malloc(sizeof(int) * len);
    for(int i = 0; i < len; i++) {
        arr[i] = input % 10;
        input  /= 10;
    }
    if(arr == NULL) exit(1);
    qsort(arr, len, sizeof(int), comp);
    for (int i = 0; i < len; i++) printf("%d", arr[i]);
    free(arr);
    return 0;
}

int comp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}