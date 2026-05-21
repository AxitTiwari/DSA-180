#include <iostream>
#include <math.h>
using namespace std;
int main() {
/*
    leetcode question.
    complement of base 10 integer.
    eg. n = 16 -> (binary) = 10000
    n' = 00001

    nahi huva , dekhta hu kaise krna.
*/
    int n;
    cin >> n;
    int ans = 0;
    int i = 0;
    //decimal -> binary
    while(n != 0) {
        int bit = n & 1; // <-- last wali bit
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1; // right shift by one bit.
        i++;
    }
    cout << "ans : " << ans << endl;
    // n = 5 -> 101 n' = 010   ...  1 -> 0  0 -> 1  ,, 123 --> 1 , 2 , 3 --> 123 ???
    int compliment = 0;
    // n --> n'
    i = 0;
    while(ans != 0) {
        int digit = ans % 10;  // last digit;
        //digit --> !digit  1 -> 0 and 0 -> 1
        int num = !digit;
        compliment = (10 * i + num) + compliment;   // 3 -> 32  10 * 1 + num = 20 + compliment = 20 + 3 = 23
        i++;
        ans = ans / 10;
    }
    cout << "complement is : " << compliment;
    return 0;
}