#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    if (num < 100) {
        cout << num / 10 + num % 10;
    } else if (num < 1000) {
        if (num / 10 == 10) {
            cout << 10 + num % 10;
        } else {
            cout << num / 100 + 10;
        }
    } else {
        cout << 20;
    }
    return 0;
}
