#include <stdio.h>
#include <stdlib.h>

typedef struct pos {
    int x, y;
} pos;

int comp(const void *elem1, const void *elem2);

int main(void) {
    int len;
    scanf("%d", &len);
    pos *point = (pos *)malloc(sizeof(pos) * len);
    for (int i = 0; i < len; i++) scanf("%d%d", &point[i].x, &point[i].y);
    qsort(point, len, sizeof(pos), comp);
    for (int i = 0; i < len; i++) printf("%d %d\n", point[i].x, point[i].y);
    free(point);
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    pos a = *(pos *)elem1;
    pos b = *(pos *)elem2;
    if (a.y > b.y) return 1;
    else if (a.y == b.y) {
        return a.x > b.x ? 1 : -1;
    }
    return -1;
}