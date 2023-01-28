#include <stdio.h>

int main(void) {
    int boyfriend, girlfriend;
    while (1) {
        scanf("%d%d", &boyfriend, &girlfriend);
        if (!boyfriend && !girlfriend) break;
        printf("%d\n", boyfriend + girlfriend);
    }
    return 0;
}