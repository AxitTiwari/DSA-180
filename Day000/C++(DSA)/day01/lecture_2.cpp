#include <iostream>
using namespace std;
int main() {
// Data Types in C++.
    int a = 123;
    cout << a << endl;

    char b = 'v';
    //char b = 'ab'; //imposible
    cout << b << endl;

    bool bl = true;
    cout << bl << endl;

    float f = 1.2;
    cout << f << endl;

    double d = 1.23;
    cout << d << endl;

    int size = sizeof(d);
    cout << "Size of d is : " << size << endl;

// Type Casting.
    int a = 'a';
    cout << a << endl;

    char ch = 98;
    cout << ch << endl;

// Memory overflow.
    char ch1 = 123456;
    cout << ch1 << endl;

//How negative numbers are stored ??

    unsigned int a = 12;
    cout << a << endl;

    int a = 2.0 / 5;
    cout << a << endl;
    cout << 2.0 / 5 << endl;

// Relational Operators
    int a = 2;
    int b = 3;

    bool first = (a == b);
    cout << first << endl;

    bool secand = (a > b);
    cout << secand << endl;

    bool third = (a < b);
    cout << third << endl;

    bool fourth = (a >= b);
    cout << fourth << endl;

    bool fifth = (a <= b);
    cout << fifth << endl;

    bool sixth = (a != b);
    cout << sixth << endl;

    int a = 21;
    cout << !a << endl;  // 0


}