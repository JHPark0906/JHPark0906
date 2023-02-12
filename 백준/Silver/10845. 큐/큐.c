#include <stdio.h>
#include <string.h>

#define MAX 10001

int main(void) {
    int queue[MAX];
    int first = 0, last = 0, iteration, tmp;
    char command[6];
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%s", command);
        if (!strcmp(command, "push")) {
            scanf("%d", &tmp);
            queue[last++] = tmp;
        } else if (!strcmp(command, "pop")) {
            printf("%d\n", first != last ? queue[first++] : -1);
        } else if (!strcmp(command, "size")) {
            printf("%d\n", last - first);
        } else if (!strcmp(command, "empty")) {
            printf("%d\n", first != last ? 0 : 1);
        } else if (!strcmp(command, "front")) {
            printf("%d\n", first != last ? queue[first] : -1);
        } else if (!strcmp(command, "back")) {
            printf("%d\n", first != last ? queue[last - 1] : -1);
        }
    }
    return 0;
}