#include <stdio.h>
#include <string.h>

#define ARR_MAX 10001
#define STR_MAX 11

typedef struct deque {
    int arr[ARR_MAX];
    int front, back;
} deque;

void pushFront(deque *deque);
void pushBack(deque *deque);
void popFront(deque *deque);
void popBack(deque *deque);
int size(deque *deque);
int empty(deque *deque);
void front(deque *deque);
void back(deque *deque);

int main(void) {
    int input;
    char command[STR_MAX];
    deque deque;
    deque.front = 0;
    deque.back = 0;
    scanf("%d", &input);
    for (int i = 0; i < input; i++) {
        scanf("%s", command);
        if (!strcmp(command, "push_front")) {
            pushFront(&deque);
        } else if (!strcmp(command, "push_back")) {
            pushBack(&deque);
        } else if (!strcmp(command, "pop_front")) {
            popFront(&deque);
        } else if (!strcmp(command, "pop_back")) {
            popBack(&deque);
        } else if (!strcmp(command, "size")) {
            printf("%d\n", size(&deque));
        } else if (!strcmp(command, "empty")) {
            printf("%d\n", empty(&deque));
        } else if (!strcmp(command, "front")) {
            front(&deque);
        } else if (!strcmp(command, "back")) {
            back(&deque);
        }
    }
    return 0;
}

void pushFront(deque *deque) {
    scanf("%d", &deque -> arr[deque -> front]);
    if (empty(deque)) deque -> back = (ARR_MAX + deque -> back + 1) % ARR_MAX;
    deque -> front = (ARR_MAX + deque -> front - 1) % ARR_MAX;
}

void pushBack(deque *deque) {
    scanf("%d", &deque -> arr[deque -> back]);
    if (empty(deque)) deque -> front = (ARR_MAX + deque -> front - 1) % ARR_MAX;
    deque -> back = (ARR_MAX + deque -> back + 1) % ARR_MAX;
}

void popFront(deque *deque) {
    int check = 0;
    if (empty(deque)) {
        printf("-1\n");
    } else {
        if (size(deque) == 1) check = 1;
        deque -> front = (ARR_MAX + deque -> front + 1) % ARR_MAX;
        printf("%d\n", deque -> arr[deque -> front]);
    }
    if (check) {
        deque -> front = 0;
        deque -> back = 0;
    }
}

void popBack(deque *deque) {
    int check = 0;
    if (empty(deque)) {
        printf("-1\n");
    } else {
        if (size(deque) == 1) check = 1;
        deque -> back = (ARR_MAX + deque -> back - 1) % ARR_MAX;
        printf("%d\n", deque -> arr[deque -> back]);
    }
    if (check) {
        deque -> front = 0;
        deque -> back = 0;
    }
}

int size(deque *deque) {
    if (deque -> back == deque -> front) return 0;
    return (ARR_MAX + deque -> back - deque -> front) % ARR_MAX - 1;
}

int empty(deque *deque) {
    return !size(deque);
}

void front(deque *deque) {
    if (empty(deque)) {
        printf("-1\n");
    } else {
        printf("%d\n", deque -> arr[(ARR_MAX + deque -> front + 1) % ARR_MAX]);
    }
}

void back(deque *deque) {
    if (empty(deque)) {
        printf("-1\n");
    } else {
        printf("%d\n", deque -> arr[(ARR_MAX + deque -> back - 1) % ARR_MAX]);
    }
}