#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int input;
    int min, max;
    scanf("%d", &input);
    int *arr = (int *)malloc(sizeof(int) * input);
    if (arr == NULL) {
        printf("NULL\n");
        exit(- 1);
    }
    for (int i = 0; i < input; i++) {
        scanf("%d", &arr[i]);
        if (i == 0) {
            min = arr[0];
            max = arr[0];
        }
        if (min > arr[i]) min = arr[i];
        if (max < arr[i]) max = arr[i];
    }
    printf("%d %d", min, max);
    free(arr);
    return 0;
}