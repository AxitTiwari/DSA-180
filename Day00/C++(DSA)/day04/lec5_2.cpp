#include <iostream>
using namespace std;
int main() {
/*
    output questions
    1.
*/
    int a, b = 1;
    a = 10;
    // ++a = 11 -> true
    if (++a)
        cout << b; // b = 1 -> output
    else
        cout << ++b;
}