#include <iostream>
#include <cstring>
using namespace std;

class Troop {
public:
    char* name;

    Troop(const char* n) {
        cout << "Default Constructor Called" << endl;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    Troop(Troop& other) {
        cout << "Deep Copy Constructor Called" << endl;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    void print() {
        cout << "Name: " << name << endl;
    }
};

int main() {
    Troop t1("Golem");
    Troop t2 = t1;   

    t1.print();
    t2.print();

    t1.name[0] = 'B';

    t1.print();
    t2.print();

    // “Give me the address of the variable name inside object t1”
    cout << "-------------------:\n ";
    cout << &(t1.name) << endl;  
    cout << &(t2.name) << endl;

    // The address stored inside the pointer
    cout << "-------------------:\n ";
    cout << (void*)(t1.name) << endl; 
    cout << (void*)(t2.name) << endl;

    return 0;
}
