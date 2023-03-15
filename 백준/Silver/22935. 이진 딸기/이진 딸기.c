#include <stdio.h>

void printBinaryStrawberry();
int convertNumber(int num);

int main(void) {
    int input;
    scanf("%d", &input);
    for (int i = 0; i < input; i++) printBinaryStrawberry();
    return 0;
}

void printBinaryStrawberry() {
    int num;
    scanf("%d", &num);
    switch (convertNumber(num)) {
        case 1:
            printf("VVV딸기\n");
            break;
        case 2:
            printf("VV딸기V\n");
            break;
        case 3:
            printf("VV딸기딸기\n");
            break;
        case 4:
            printf("V딸기VV\n");
            break;
        case 5:
            printf("V딸기V딸기\n");
            break;
        case 6:
            printf("V딸기딸기V\n");
            break;
        case 7:
            printf("V딸기딸기딸기\n");
            break;
        case 8:
            printf("딸기VVV\n");
            break;
        case 9:
            printf("딸기VV딸기\n");
            break;
        case 10:
            printf("딸기V딸기V\n");
            break;
        case 11:
            printf("딸기V딸기딸기\n");
            break;
        case 12:
            printf("딸기딸기VV\n");
            break;
        case 13:
            printf("딸기딸기V딸기\n");
            break;
        case 14:
            printf("딸기딸기딸기V\n");
            break;
        case 15:
            printf("딸기딸기딸기딸기\n");
            break;
    }
}

int convertNumber(int num) {
    num %= 28;
    if (!num) return 2;
    if (num >= 15) return 30 - num;
    else return num;
}