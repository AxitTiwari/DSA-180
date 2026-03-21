#include <iostream>
#include <math.h>
using namespace std;
int main() {
/*
    lec6 skip ho gaya tha , fir dekhna hoga.

    Decimal & Binary
    Decimal -> base 10
    Binary -> base 2

    Convertion
    Decimal --> Binary
    eg. let n = 10 (1010)
    step 1) number divide by 2  -> 10 / 2 = 5   5 / 2 = 2   2 / 2 = 1   1 / 2 = 0
    2) store remender        rem = 0 (repeat)   rem = 1     rem = 0     rem = 1  == 0101 -> reverse = (1010)2 = (10)10
    3) repeat above two steps
    4) reverse 

    n = 10 / 2 = 5 rem = 0 10 % 2 = 0 5 % 2 = 1 5 / 2 = 2 rem = 1

    2nd logic
    eg. let n = 5 = 101 in binary
    ans = i = 0;
    jab tk(n != 0) {
        bit = n & 1;
        ans = (bit * (10 ^ i) + ans;
        n = n >> 1;
        i++;
    }

    Binary --> Decimal
    7 = 111
    """1 * 2^2 + 1 * 2^1 + 1 * 2^0""" = 4 + 2 + 1 = 7

    123 -> 321
    ans = 0;
    ans = (10 ^ i ) * digit + ans;

*/
    //decimal to binary.
    unsigned int n;
    cout << "input: ";
    cin >> n;

    unsigned int answer = 0;
    int i = 0;
    while(n != 0) {
        int bit = n & 1;   // extract last bit
        answer = (bit * pow(10 , i)) + answer;  // collect all bits together to build the number.
        n = n >> 1;
        i++;
    }
    cout << "answer is : " << answer << endl;
    return 0;
}