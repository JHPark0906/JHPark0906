#include <iostream>

using namespace std;

int main() {
    int hanyang, korea, soongsil;
    cin >> soongsil >> korea >> hanyang;
    if (hanyang + korea + soongsil < 100)
        cout << ((soongsil < korea && soongsil < hanyang) ? "Soongsil" : ((korea < soongsil && korea < hanyang) ? "Korea" : "Hanyang"));
    else
        cout << "OK";
    return 0;
}
