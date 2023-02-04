#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int input, size = 0;
    scanf("%d", &input);
    int *stack = (int *)malloc(sizeof(int) * input);
    char instruction[6];
    int tmp;
    for (int i = 0; i < input; i++) {
        scanf("%s", instruction);
        if (!strcmp(instruction, "push")) {
            scanf("%d", &stack[size++]);
        }
        if (!strcmp(instruction, "pop")) {
            printf("%d\n", size == 0 ? -1 : stack[--size]);
        }
        if (!strcmp(instruction, "size")) {
            printf("%d\n", size);
        }
        if (!strcmp(instruction, "empty")) {
            printf("%d\n", size == 0 ? 1 : 0);
        }
        if (!strcmp(instruction, "top")) {
            printf("%d\n", size == 0 ? -1 : stack[size - 1]);
        }
    }
    free(stack);
    return 0;
}