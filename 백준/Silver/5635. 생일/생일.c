#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char name[16];
    int day, month, year;
} student;

// 나이가 제일 많은 사람이 0번
int comp(const void *elem1, const void *elem2);

int main(void) {
    int input;
    scanf("%d", &input);
    student *students = (student *)malloc(sizeof(student) * input);
    for (int i = 0; i < input; i++)
        scanf("%s%d%d%d", students[i].name, &students[i].day, &students[i].month, &students[i].year);
    qsort(students, input, sizeof(student), comp);
    printf("%s\n%s", students[input - 1].name, students[0].name);
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    student a = *(student *)elem1;
    student b = *(student *)elem2;
    if (a.year != b.year)
        return a.year - b.year;
    else if (a.month != b.month)
        return a.month - b.month;
    else
        return a.day - b.day;
}