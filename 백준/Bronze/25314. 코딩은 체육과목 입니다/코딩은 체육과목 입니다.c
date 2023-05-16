#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);
    num /= 4;
    for (int i = 0; i < num; i++)
        printf("long ");
    printf("int");
    return 0;
}