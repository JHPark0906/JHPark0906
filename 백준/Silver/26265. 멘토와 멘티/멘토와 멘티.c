#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pair {
    char mentor[21], mentee[21];
} pair;

int comp(const void *elem1, const void *elem2);

int main(void) {
    int size;
    scanf("%d", &size);
    pair *arr = (pair *)malloc(sizeof(pair) * size);
    for (int i = 0; i < size; i++) scanf("%s%s", arr[i].mentor, arr[i].mentee);
    qsort(arr, size, sizeof(pair), comp);
    for (int i = 0; i < size; i++) printf("%s %s\n", arr[i].mentor, arr[i].mentee);
    free(arr);
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    pair a = *(pair *)elem1;
    pair b = *(pair *)elem2;
    if (!strcmp(a.mentor, b.mentor)) return strcmp(b.mentee, a.mentee);
    return strcmp(a.mentor, b.mentor);
}