#include <iostream>

using std::cout;
using std::endl;

class Troops {
private:
    // data members
    std::string name = "P.E.K.K.A";
    int health = 8000;
    int level = 9;

public:
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

    // pekka.health = 100000; // -> error

    pekka.printStatus();

    return 0;
}