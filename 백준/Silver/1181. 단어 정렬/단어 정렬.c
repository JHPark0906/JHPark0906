#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *elem1, const void *elem2);

int main(void) {
    int len;
    scanf("%d", &len);
    char **arr = (char **)malloc(sizeof(char *) * len);
    for (int i = 0; i < len; i++) {
        arr[i] = (char *)malloc(sizeof(char) * 51);
    }
    for (int i = 0; i < len; i++) scanf("%s", arr[i]);
    qsort(arr, len, sizeof(char *), comp);
    for (int i = 0; i < len; i++) {
        if (!i) printf("%s\n", arr[0]);
        else if (strcmp(arr[i - 1], arr[i])) printf("%s\n", arr[i]);
    }
    free(arr);
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    int len1 = strlen(*(char **)elem1);
    int len2 = strlen(*(char **)elem2);
    if (len1 > len2) return 1;
    else if (len1 < len2) return -1;
    else return strcmp(*(char **)elem1, *(char **)elem2);
}