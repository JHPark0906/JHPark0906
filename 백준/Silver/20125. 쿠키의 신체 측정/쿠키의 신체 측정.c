#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int len;
    scanf("%d", &len);
    char *plate = (char *)malloc(sizeof(char) * (len + 1));

    int headPosI = -1, headPosJ;
    int leftArm = 0, rightArm = 0, body = 0, leftLeg = 0, rightLeg = 0;
    for (int i = 0; i < len; i++) {
        scanf("%s", plate);
        for (int j = 0; j < len; j++) {
            if (headPosI == -1 && plate[j] == '*') {
                headPosI = i;
                headPosJ = j;
            }
            if (headPosI != -1) {
                if (i == headPosI + 1 && plate[j] == '*') {
                    if (j < headPosJ) leftArm++;
                    else if (j > headPosJ) rightArm++;
                }
                if (i > headPosI + 1 && plate[j] == '*') {
                    if (j == headPosJ && plate[j] == '*') body++;
                    else if (j == headPosJ - 1) leftLeg++;
                    else if (j == headPosJ + 1) rightLeg++;
                }
            }


        }
    }
    printf("%d %d\n%d %d %d %d %d", headPosI + 2, headPosJ + 1, leftArm, rightArm, body, leftLeg, rightLeg);
    free(plate);
    return 0;
}