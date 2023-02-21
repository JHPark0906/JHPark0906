#include <stdio.h>

int main(void) {
    int temperature, goal, minus, melt, plus;
    scanf("%d%d%d%d%d", &temperature, &goal, &minus, &melt, &plus);
    printf("%d", temperature < 0 ? melt + goal * plus - temperature * minus : plus * (goal - temperature));
    return 0;
}