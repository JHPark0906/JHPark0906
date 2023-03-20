#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX_LENGTH 11
#define STUDENT_MAX 100000

typedef struct score {
    char name[NAME_MAX_LENGTH];
    int korean, english, math;
} score;

int comp(const void *elem1, const void *elem2);

int main(void) {
    score scores[STUDENT_MAX];
    int student;
    scanf("%d", &student);
    for (int i = 0; i < student; i++) {
        scanf("%s %d%d%d", scores[i].name, &scores[i].korean, &scores[i].english, &scores[i].math);
    }
    qsort(scores, student, sizeof(score), comp);
    for (int i = 0; i < student; i++) {
        printf("%s\n", scores[i].name);
    }
    return 0;
}

int comp(const void *elem1, const void *elem2){
    score a, b;
    a = *(score *)elem1;
    b = *(score *)elem2;
    if (a.korean != b.korean) {
        return b.korean - a.korean;
    }
    if (a.english != b.english) {
        return a.english - b.english;
    }
    if (a.math != b.math) {
        return b.math - a.math;
    }
    return strcmp(a.name, b.name);
}