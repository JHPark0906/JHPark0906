#include <iostream>

using namespace std;

void printPointer(int num);

int main() {
    int num;
    cin >> num;
    cout << "int a;" << endl;
    for (int i = 1; i <= num; i++)
        printPointer(i);
    return 0;
}

void printPointer(int num) {
    cout << "int ";
    for (int i = 0; i < num; i++)
        cout << "*";
    cout << "ptr";
    if (num == 1)
        cout << " = &a;" << endl;
    else if (num == 2)
        cout << "2 = &ptr;" << endl;
    else
        cout << num << " = &ptr" << num - 1 << ";" << endl;
}