#include <iostream>

using std::cout;
using std::endl;

class Troop {
public:
    std::string name;
    int health;
    int level;

    Troop(std::string name, int health, int level) {
        cout << "this(stores address of current object): " << this << endl;
        this->name = name;
        this->health = health;
        this->level = level;
    }

    void printInfo() {
        cout << "-----------------------------\n";
        cout << "Name: " << this->name << endl;
        cout << "Health: " << this->health << endl;
        cout << "Level: " << this->level << endl;
        cout << "-----------------------------\n";
    }

};

int main() {
    
    Troop archer("Archer:", 400, 5);
    cout << "Address of archer object: " << &archer << endl;
    archer.printInfo();

    Troop pekka("P.E.K.K.A", 8000, 9);
    cout << "Address of pekka object: " << &pekka << endl;
    pekka.printInfo();

    return 0;
}