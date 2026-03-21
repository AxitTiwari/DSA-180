#include <iostream>
using namespace std;

void update(int a) {
    a = a / 2;
}

int main() {
/*
    output 1.
*/
    int a = 10;

    update(a);
    // no effect

    cout << a << endl;  // -> 10

}