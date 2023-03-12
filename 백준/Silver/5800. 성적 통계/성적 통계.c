#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int comp (const void *elem1, const void *elem2);

int main(void) {
    int iteration, student, score[MAX], gap;
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%d", &student);
        for (int j = 0; j < student; j++) scanf("%d", &score[j]);
        qsort(score, student, sizeof(int), comp);
        gap = 0;
        for (int k = 1; k < student; k++) {
            if (score[k - 1] - score[k] > gap) gap = score[k - 1] - score[k];
        }
        printf("Class %d\n", i + 1);
        printf("Max %d, Min %d, Largest gap %d\n", score[0], score[student - 1], gap);
    }
    return 0;
}

int comp (const void *elem1, const void *elem2) {
    return (*(int *)elem2) - (*(int *)elem1);
}