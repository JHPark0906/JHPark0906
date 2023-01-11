#include <stdio.h>
#include <math.h>

int main(void) {
    char input1[4], input2[4];
    scanf("%s%s", input1, input2);
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++) {
        a += pow(10, i) * (input1[i] - 48);
        b += pow(10, i) * (input2[i] - 48);
    }
    printf("%d", a < b ? b : a);
    return 0;
}