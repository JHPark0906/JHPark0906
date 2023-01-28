#include <stdio.h>

int main(void) {
    int human, size;
    int newspaper[5];
    scanf("%d%d", &human, &size);
    int partyPeople = human * size;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &newspaper[i]);
        printf("%d ", newspaper[i] - partyPeople);
    }
    return 0;
}