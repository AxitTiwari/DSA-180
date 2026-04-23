#include <iostream>

using std::cout;
using std::endl;

class Troop {
private:
    // data members
    std::string name = "P.E.K.K.A";
    int health = 8000;
    int level = 9;

public:
    // getter
    std::string getName() {
        return name;
    }

    int getHealth() {
        return health;
    }

    int getLevel() {
        return level;
    }

    // setter
    void setName(std::string n) {
        name = n;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(int l) {
        level = l;
    }


};

int main() {
    
    Troop pekka;

    cout << "--------Initial values:--------" << endl;

    // --------getters----------
    cout << pekka.getName() << endl;
    cout << pekka.getHealth() << endl;
    cout << pekka.getLevel() << endl;
    // -------------------------

    // --------setters----------
    pekka.setName("Dragon");
    pekka.setHealth(5000);
    pekka.setLevel(7);
    // -------------------------

    cout << "-------After using setters:--------" << endl;

    cout << pekka.getName() << endl;
    cout << pekka.getHealth() << endl;
    cout << pekka.getLevel() << endl;

    return 0;
}