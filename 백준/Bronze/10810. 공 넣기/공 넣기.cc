#include <iostream>
using namespace std;

#define ARR_MAX 100

int main() {
    int size, input, arr[ARR_MAX] = {0}, start, end, num;
    cin >> size >> input;
    for (int i = 0; i < input; i++) {
        cin >> start >> end >> num;
        start--; end--;
        for (int j = start; j <= end; j++)
            arr[j] = num;
    }
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    return 0;
}