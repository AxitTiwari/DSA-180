#include <iostream>

using std::cout;
using std::endl;

class Troop {
public:
    std::string name;
    int health;
    int level;

    static int timeLeft;

    Troop() {

    }

    Troop(std::string name, int health, int level) {
        this->name = name;
        this->health = health;
        this->level = level;
    }

    static int getTimeLeft() {
        return timeLeft;
    }

};

int Troop::timeLeft = 2;

int main() {

    cout << "time left: " << Troop::getTimeLeft() << endl;
    
    return 0;
}