#include <iostream>

using namespace std;

class Troop {
private:
    int hp;
    int dps;
    int level;

public:

    string name;

    int getHp() const{
        return hp;
    }

    int getDps() const{
        return dps;
    }

    int getLevel() const{
        return level;
    }
};

// Inheritance
class Healer : protected Troop {
public:
    int healingPower;

public:

    int getHealingPower() const{
        return healingPower;
    }

    void setHealingPower(int heal) {
        healingPower = heal;
    }
};

int main() {

    Healer healer;

    // cannot modify protected members of base class
    // public - protected - protected
    // healer.name = "Healer";

    healer.setHealingPower(150);
    cout << healer.getHealingPower() << endl;
    return 0;
}