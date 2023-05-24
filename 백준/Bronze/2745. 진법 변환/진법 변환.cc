#include <iostream>
#include <cstring>

#define MAX 32

int getDecimal(char* number, int digit);
int power(int base, int exponent);

int main() {
    char num[MAX];
    int digit;
    std::cin >> num >> digit;
    std::cout << getDecimal(num, digit);
    return 0;
}

int getDecimal(char* number, int digit) {
    char tmp;
    int result = 0;
    int len = strlen(number);
    for (int i = 0; i < len; i++) {
        tmp = number[len - 1 - i];
        result += power(digit, i) * ('0' <= tmp && tmp <= '9' ? tmp - '0' : tmp - 'A' + 10);
    }
    return result;
}

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}
