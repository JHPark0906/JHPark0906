#include <stdio.h>
#include <stdlib.h>

typedef struct monitor {
    int idx, ppi;
} monitor;

int comp(const void *elem1, const void *elem2);

int main(void) {
    int num, w, h;
    scanf("%d", &num);
    monitor *monitors = (monitor *)malloc(sizeof(monitor) * num);
    for (int i = 0; i < num; i++) {
        scanf("%d%d", &w, &h);
        monitors[i].idx = i + 1;
        monitors[i].ppi = w * w + h * h;
    }
    qsort(monitors, num, sizeof(monitor), comp);
    for (int i = 0; i < num; i++) {
        printf("%d\n", monitors[i].idx);
    }
    free(monitors);
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    return (*(monitor *)elem2).ppi - (*(monitor *)elem1).ppi;
}