#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int input;
    scanf("%d", &input);
    int student, goodStudents, sum;
    double average;
    int *score = (int *)malloc(sizeof(int));
    for (int i = 0; i < input; i++) {
        goodStudents = 0;
        sum = 0;
        scanf("%d", &student);
        score = (int *)realloc(score, sizeof(int) * student);
        for (int j = 0; j < student; j++) {
            scanf("%d", &score[j]);
            sum += score[j];
        }
        average = (double)sum / student;
        for (int j = 0; j < student; j++) {
            if (score[j] > average) goodStudents++;
        }
        printf("%.3lf%%\n", ((double)goodStudents / student) * 100);
    }
    return 0;
}