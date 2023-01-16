#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size;
    scanf("%d", &size);
    double *score = (double *) malloc(sizeof(double ) * size);
    double max = 0.0;
    for (int i = 0; i < size; i++) {
        scanf("%lf", &score[i]);
        if (score[i] > max) max = score[i];
    }
    double mean = 0.0;
    for (int i = 0; i < size; i++) {
        score[i] = score[i] / max * 100.0;
        mean += score[i] / size;

    }
    printf("%lf", mean);
    return 0;
}