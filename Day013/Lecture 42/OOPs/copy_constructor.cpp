#include <iostream>

using std::cout;
using std::endl;

class Troop {
public:
    std::string name;
    int health;
    int level;

    Troop(std::string name, int health, int level) {
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
    
    Troop golem1("Golem:", 10000, 5);
    golem1.printInfo();

    Troop golem2(golem1);
    golem2.printInfo();

    return 0;
}