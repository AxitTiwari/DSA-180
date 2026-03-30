#include <iostream>
using namespace std;

int totalSetBits(int a) {

    int count = 0;
    while(a != 0) {
        if(a & 1) {
            count++;
        }
        a = a >> 1;
    }

    return count;
}

int main() {
    int a, b;
    cin >> a >> b;

    int ans = totalSetBits(a) + totalSetBits(b);
    cout << ans << endl;
    return 0;
}