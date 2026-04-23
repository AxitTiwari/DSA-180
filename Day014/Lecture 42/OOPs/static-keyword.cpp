#include <iostream>
#include <cstring>
using namespace std;

class Troop {
public:
    char* name;
    static int timeLeft;

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

int Troop::timeLeft = 2;

int main() {

    cout << "Time Left: " << Troop::timeLeft  << " min" << endl;

    return 0;
}
