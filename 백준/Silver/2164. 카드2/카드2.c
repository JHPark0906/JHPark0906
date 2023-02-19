#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int len, start = 0, end, cnt = 0;
    scanf("%d", &len);
    int *arr = (int *)malloc(sizeof(int) * len * 2);
    for (int i = 0; i < len; i++) arr[i] = i + 1;
    end = len;
    while (start < end) {
        if (cnt) {
            arr[end++] = arr[start];
            cnt = 0;
        } else cnt = 1;
        start++;
    }
    printf("%d", arr[start - 1]);
    return 0;
}