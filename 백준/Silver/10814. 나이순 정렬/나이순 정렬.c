#include <stdio.h>
#include <stdlib.h>

typedef struct member {
    int age, idx;
    char name[101];
} member;

int comp(const void *elem1, const void *elem2);

int main() {
    int len;
    scanf("%d", &len);
    member *members = (member *)malloc(sizeof(member) * len);
    for (int i = 0; i < len; i++) {
        scanf("%d%s", &members[i].age, members[i].name);
        members[i].idx = i;
    }
    qsort(members, len, sizeof(member), comp);
    for (int i = 0; i < len; i++) printf("%d %s\n", members[i].age, members[i].name);
    free(members);
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    int age = ((member *)elem1) -> age - ((member *)elem2) -> age;
    return age != 0 ? age : ((member *)elem1) -> idx - ((member *)elem2) -> idx;
}