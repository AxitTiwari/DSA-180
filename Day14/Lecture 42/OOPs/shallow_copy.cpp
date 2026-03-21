#include <iostream>
#include <cstring>
using namespace std;

class Troop {
public:
    char* name;

    Troop(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Default copy constructor (shallow copy)
    // Compiler copies pointer only

    void print() {
        cout << "Name: " << name << endl;
    }
};

int main() {
    Troop t1("Golem");
    Troop t2 = t1;   // SHALLOW COPY

    t1.print();
    t2.print();

    t1.name[0] = 'B';

    t1.print();
    t2.print();

    cout << "-------------------:\n ";
    cout << &(t1.name) << endl;  // “Give me the address of the variable name inside object t1”
    cout << &(t2.name) << endl;

    // The address stored inside the pointer
    cout << "-------------------:\n ";
    cout << (void*)(t1.name) << endl; 
    cout << (void*)(t2.name) << endl;

    return 0;
}
