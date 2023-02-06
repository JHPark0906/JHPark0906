#include <stdio.h>
#include <string.h>
#define MAX 2000001

/*
 * first: 큐의 처음 원소의 인덱스
 * last: 큐의 마지막 원소의 인덱스
 * size: 현재 큐에 할당된 메모리 크기
 * elem: 큐에 있는 원소의 개수
 */
int main(void) {
    int iteration, num, first = 0, last = 0, elem = 0, queue[MAX];
    char command[6];
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%s", command);
        if (!strcmp(command, "push")) {
            scanf("%d", &num);
            queue[last] = num;
            last++;
            elem++;
        } else if (!strcmp(command, "pop")) {
            if (elem) {
                printf("%d\n", queue[first]);
                first++;
                elem--;
            } else {
                printf("-1\n");
            }
        } else if (!strcmp(command, "size")) {
            printf("%d\n", elem);
        } else if (!strcmp(command, "empty")) {
            printf("%d\n", elem ? 0 : 1);
        } else if (!strcmp(command, "front")) {
            printf("%d\n", elem ? queue[first] : -1);
        } else if (!strcmp(command, "back")) {
            printf("%d\n", elem ? queue[last - 1] : -1);
        }
    }
    return 0;
}