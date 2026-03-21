#include <iostream>

using namespace std;

class A {
public:
    void func1() {
        cout << "function 1\n";
    }
};

class B : public A {
public:
    void func2() {
        cout << "function 2\n";
    }
};

class C : public A {
public:
    void func3() {
        cout << "function 3\n";
    }
};

int main() {

    A a;
    a.func1();

    B b;
    b.func2();
    b.func1();

    C c;
    c.func3();
    c.func1();

    return 0;
}