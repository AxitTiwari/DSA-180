#include <iostream>
using namespace std;
int main() {
/*
    leetcode question
    2. Number of 1 Bits(191)
    eg. 5 = 101 = 2
    8 = 1000 = 8
    number -> binary
    8 4 2 1
    2 aproaches
    1. convert number to binary
    2. check last digit then right shift by 1 then again check.
    if number become zero then break in 2nd condition
*/
    int n;
    cin >> n;
    int count = 0;
    while(n != 0) {
        //checking last bit
        if(n & 1) {
            //let n = 0000101 & 1 = 1 <- true means 1 if false then it will be zero
            count++; // only when condition is true means 1
        }
        n = n >> 1; //right shift by 1 . for eg -> 0000101 << 1 == 000010
    }
    cout << count << endl;
    return 0;
}