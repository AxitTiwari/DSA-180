#include <iostream>
using namespace std;
int main() {
    // 2.
    int a = 1;
    int b = 2;

    // (a = 1 , a-- = 1 > 0 -> true ) or --> ye wali condition check nahi hogi kyuki first true ho gai (b = 2, ++b = 3 > 2 -> true) --> true
    // b -> remain same.
    if (a-- > 0 || ++b > 2) {
        cout << "Stage1 - Inside If" << endl; // <-- output
    }
    else {
        cout << "Stage2 - Inside else";
    }
    cout << a << " " << b << endl; // a = 0 , b = 2
}