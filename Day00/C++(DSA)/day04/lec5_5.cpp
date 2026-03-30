#include <iostream>
using namespace std;
int main() {
    // 4.
    int a = 1;
    // b = 1 
    int b = a++;
    //a = 2
    // c = 3
    int c = ++a;
    cout << b; // b = 1
    cout << c; // c = 3
}