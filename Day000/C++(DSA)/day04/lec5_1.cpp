#include <iostream>
using namespace std;
int main() {
// Operators & For loop
/*
    1. Bitwise operator
    AND - & -> works at bit level
    OR  - |
    NOT - ~
    XOR - ^
*/
    int a = 4;
    int b = 6;
    cout << "a&b = " << (a & b)<< endl;
    cout << "a|b = " << (a | b)<< endl;
    cout << "~a = " << (~a)<< endl;
    cout << "a^b = " << (a ^ b)<< endl;
/*
    Left shift and Right shift

    Left shift
    5 << 1
    5 (in binary) = 00000.....101
    left shift by 1 means --> 0000....1010 = 10
    5(left shift by 1) --> 10 (answer)
    5 --> 5 * 2 = 10(left shift by 1 answer)
    3 << 2
    3 = 0000......011  --> 0000......01100
    3(left shift by 2) --> 12 (answer)
    3 -> 3 * 2 = 6 -> 6 * 2 = 12(answer)

    some cases -> negative number ho jaega
    when number bahut bada hoga tb.

    Right shift
    5 >> 2
    5 in binary = 000....101  --> right shift by 2 --> 0000......1
    5(right shift by 2) --> 1 (answer)
    5 -> 5/2 = 2 -> 2/2 = 1

    "<< , >> (left shift , right shift) -> +ve number -> padding with 0."
    "<< , >> (left shift , right shift) -> -ve number -> padding dependent on compiler."
*/
    cout << "17 >> 1 = (right shift) " << (17 >> 1) << endl;
    cout << "17 >> 2 = (right shift) " << (17 >> 2) << endl;
    cout << "19 << 1 = (left shift)  " << (19 << 1) << endl;
    cout << "21 << 2 = (left shift)  " << (21 << 2) << endl;
/*
    post-increment/pre-increment operator
    (i++/++i)
    i++ -> first use then increment
    --i -> first decrement then use
*/
    int i = 10;
    int num = ++i;
    cout << "num = " << num << endl;
    cout << "i   =  " << i << endl;
    cout << "i++(first use then increment) =  " << (i++) << endl;
    cout << "i   =  " << i << endl;
    cout << "++i(first decrement then use) =  " << (++i) << endl;
    cout << "i   =  " << i << endl;

}