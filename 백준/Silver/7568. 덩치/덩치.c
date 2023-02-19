#include <stdio.h>
#include <stdlib.h>

typedef struct human {
    int weight, height, bigger;
} human;

int main(void) {
    // 입력
    int input;
    scanf("%d", &input);
    human *humans = (human *)malloc(sizeof(human) * input);
    for (int i = 0; i < input; i++) scanf("%d%d", &humans[i].weight, &humans[i].height);

    // 덩치가 더 큰 사람 수 측정
    for (int i = 0; i < input; i++) {
        humans[i].bigger = 0;
        for (int j = 0; j < input; j++) {
            if (humans[i].weight < humans[j].weight && humans[i].height < humans[j].height)
                humans[i].bigger++;
        }
    }

    // 출력
    for (int i = 0; i < input; i++) printf("%d ", humans[i].bigger + 1);
    return 0;
}