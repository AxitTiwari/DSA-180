#include <iostream>
#include <math.h>
using namespace std;
int main() {
/*
    binary to decimal convertion.

*/
    int n;
    cin >> n;
    int ans = 0;
    int i = 0;
    while(n != 0) {
        int digit = n % 10; // 1010 % 10 = 0
        if(digit) {
            ans = pow(2, i) + ans;
        }
        i++;
        n = n / 10;  
    }
    cout << "answer is : " << ans << endl;
    return 0;
}