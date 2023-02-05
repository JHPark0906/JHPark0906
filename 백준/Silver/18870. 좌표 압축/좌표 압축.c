#include <stdio.h>
#include <stdlib.h>

typedef struct pos {
    int x, idx, compress;
} pos;

int compX(const void *elem1, const void *elem2);
int compIdx(const void *elem1, const void *elem2);

int main(void) {
    int len;
    scanf("%d", &len);
    pos *arr = (pos *)malloc(sizeof(pos) * len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i].x);
        arr[i].idx = i;
    }
    qsort(arr, len, sizeof(pos), compX);
    for (int i = 0; i < len; i++) {
        if (!i) arr[0].compress = 0;
        else arr[i].compress = arr[i - 1].x == arr[i].x ? arr[i - 1].compress : arr[i - 1].compress + 1;
    }
    qsort(arr, len, sizeof(pos), compIdx);
    for (int i = 0; i < len; i++) printf("%d ", arr[i].compress);
    free(arr);
    return 0;
}

int compX(const void *elem1, const void *elem2) {
    return (*(pos *)elem1).x - (*(pos *)elem2).x;
}

int compIdx(const void *elem1, const void *elem2) {
    return (*(pos *)elem1).idx - (*(pos *)elem2).idx;
}