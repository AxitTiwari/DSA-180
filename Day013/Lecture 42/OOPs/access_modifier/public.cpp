#include <iostream>

using std::cout;
using std::endl;

class Troops {

public:

    // data members
    std::string name;
    int health;
    int level;

    // method
    void printStatus() {
        cout << "------your charecter---------\n";
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Level: " << level << endl;
        cout << "-----------------------------\n";
    }
};

int main() {
    
    Troops pekka;

    pekka.name = "P.E.K.K.A";
    pekka.health = 8000;
    pekka.level = 9;

    pekka.printStatus();

    // cout << "------your charecter---------\n";
    // cout << "Name: " << pekka.name << endl;
    // cout << "Health: " << pekka.health << endl;
    // cout << "Level: " << pekka.level << endl;
    // cout << "-----------------------------\n";

    return 0;
}