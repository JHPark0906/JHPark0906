#include <stdio.h>
#include <string.h>

#define MAX 201

void convert(char input[MAX], char output[MAX]);
void snakeToCamel(char input[MAX], char output[MAX]);
void camelToSnake(char input[MAX], char output[MAX]);

int main(void) {
    char input[MAX], output[MAX];
    scanf("%s", input);
    convert(input, output);
    printf("%s", output);
    return 0;
}

void convert(char input[MAX], char output[MAX]) {
    int len = strlen(input), underBar = 0, upperCase = 0;
    for (int i = 0; i < len; i++) {
        if (input[i] == '_') underBar++;
        else if ('A' <= input[i] && input[i] <= 'Z') upperCase++;
        if (i) {
            if (input[i - 1] == '_' && input[i] == '_') {
                strcpy(output, "Error!");
                return;
            }
        }
    }
    if ((underBar && upperCase) || (input[0] == '_') || ('A' <= input[0] && input[0] <= 'Z') || (input[len - 1] == '_')) {
        strcpy(output, "Error!");
    } else if (!underBar && !upperCase) {
        strcpy(output, input);
    } else if (underBar) {
        snakeToCamel(input, output);
    } else {
        camelToSnake(input, output);
    }
}

void snakeToCamel(char input[MAX], char output[MAX]) {
    int len = strlen(input), idx = 0;
    for (int i = 0; i < len; i++) {
        if (input[i] == '_') {
            i++;
            output[idx++] = input[i] - 32;
        } else {
            output[idx++] = input[i];
        }
    }
    output[idx] = '\0';
}

void camelToSnake(char input[MAX], char output[MAX]) {
    int len = strlen(input), idx = 0;
    for (int i = 0; i < len; i++) {
        if ('A' <= input[i] && input[i] <= 'Z') {
            output[idx++] = '_';
            output[idx++] = input[i] + 32;
        } else {
            output[idx++] = input[i];
        }
    }
    output[idx] = '\0';
}