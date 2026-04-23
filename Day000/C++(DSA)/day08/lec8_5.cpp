#include <iostream>
using namespace std;

int power(int a, int b) {

    int ans = 1;
    for(int i = 1; i <= b; i++) {
        ans = ans * a;
    }

    return ans;
}

int main() {
/*
    functions
*/
    int a, b;
    cin >> a >> b;

    int ans = power(a, b);

    cout << "Power of " << a << " raised to " << b << " is: " << ans << endl;
    return 0;
}