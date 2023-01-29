#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int len, target, result = 0;
    scanf("%d", &len);
    int *arr = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) scanf("%d", &arr[i]);
    scanf("%d", &target);
    for (int i = 0; i < len; i++) if (arr[i] == target) result++;
    printf("%d", result);
    return 0;
}