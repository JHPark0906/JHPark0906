#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ELEM_MAX 20
#define STR_MAX 7

void addElement(bool set[ELEM_MAX]);
void removeElement(bool set[ELEM_MAX]);
void check(bool set[ELEM_MAX]);
void toggleElement(bool set[ELEM_MAX]);
void all(bool set[ELEM_MAX]);
void empty(bool set[ELEM_MAX]);

int main(void) {
    int input;
    char command[STR_MAX];
    bool set[ELEM_MAX] = {false};
    scanf("%d", &input);
    for (int i = 0; i < input; i++) {
        scanf("%s", command);
        if (!strcmp(command, "add")) {
            addElement(set);
        } else if (!strcmp(command, "remove")) {
            removeElement(set);
        } else if (!strcmp(command, "check")) {
            check(set);
        } else if (!strcmp(command, "toggle")) {
            toggleElement(set);
        } else if (!strcmp(command, "all")) {
            all(set);
        } else if (!strcmp(command, "empty")) {
            empty(set);
        }
    }
    return 0;
}

void addElement(bool set[ELEM_MAX]) {
    int idx;
    scanf("%d", &idx);
    set[idx - 1] = true;
}

void removeElement(bool set[ELEM_MAX]) {
    int idx;
    scanf("%d", &idx);
    set[idx - 1] = false;
}

void check(bool set[ELEM_MAX]) {
    int idx;
    scanf("%d", &idx);
    printf("%d\n", set[idx - 1] ? 1 : 0);
}

void toggleElement(bool set[ELEM_MAX]) {
    int idx;
    scanf("%d", &idx);
    set[idx - 1] = !set[idx - 1];
}

void all(bool set[ELEM_MAX]) {
    for (int i = 0; i < 20; i++) set[i] = true;
}

void empty(bool set[ELEM_MAX]) {
    for (int i = 0; i < 20; i++) set[i] = false;
}