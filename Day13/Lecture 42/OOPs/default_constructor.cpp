#include <iostream>

using std::cout;
using std::endl;

class Troop {
public:
    std::string name;
    int health;
    int level;

    Troop() {
        cout << "Default Constructor Called!" << endl;
    }

};

int main() {
    
    Troop archer;

    archer.name = "Archer";
    archer.health = 400;
    archer.level = 5;

    Troop pekka;

    pekka.name = "peka";
    pekka.health = 8000;
    pekka.level = 9;

    return 0;
}