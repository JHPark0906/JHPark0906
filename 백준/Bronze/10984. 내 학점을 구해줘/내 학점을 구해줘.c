#include <stdio.h>

int main(void) {
    int semester, subject, credit, totalCredit;
    double grade, totalGrade;
    scanf("%d", &semester);
    for (int i = 0; i < semester; i++) {
        totalCredit = 0;
        totalGrade = 0.0;
        scanf("%d", &subject);
        for (int j = 0; j < subject; j++) {
            scanf("%d%lf", &credit, &grade);
            totalCredit += credit;
            totalGrade += grade * credit;
        }
        printf("%d %0.1lf\n", totalCredit, totalGrade / totalCredit);
    }
    return 0;
}