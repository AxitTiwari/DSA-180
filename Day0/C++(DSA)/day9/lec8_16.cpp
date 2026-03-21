#include <iostream>
using namespace std;

int update(int a) {

    a -= 5;
    return a;
}

int main() {
/*
    2.
*/
    int a = 15;

    // no effect.
    update(a);

    cout << a << endl;
}