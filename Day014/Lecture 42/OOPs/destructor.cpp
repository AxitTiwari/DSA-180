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

    ~Troop() {
        cout << "Destructor Called for " << name << endl;
        delete[] name;
    }
};

int main() {

    // STATIC allocation
    Troop t1("P.E.K.K.A");

    // DYNAMIC allocation
    Troop* t2 = new Troop("Witch");

    t1.print();
    t2->print();

    // manual deallocation -> dynamic memory
    delete t2;

    return 0;
}
