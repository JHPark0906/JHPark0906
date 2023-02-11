#include <stdio.h>
#include <stdlib.h>

int comp(const void *elem1, const void *elem2);

int main(void) {
    int length[3] = {1, 1, 1};
    while(1) {
        for (int i = 0; i < 3; i++) scanf("%d", &length[i]);
        if (!length[0] && !length[1] && !length[2]) break;
        else if (!length[0] || !length[1] || !length[2]) printf("Invalid\n");
        qsort(length, 3, sizeof(int), comp);
        if (length[2] >= length[0] + length[1]) printf("Invalid\n");
        else if (length[0] == length[1]) {
            if (length[1] == length[2]) printf("Equilateral\n");
            else printf("Isosceles\n");
        } else {
            if (length[1] == length[2]) printf("Isosceles\n");
            else printf("Scalene\n");
        }
    }

    return 0;
}

int comp(const void *elem1, const void *elem2) {
    return (*(int *)elem1) - (*(int *)elem2);
}