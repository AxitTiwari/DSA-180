#include <iostream>

using namespace std;

class Troop {
public:
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

    // -------assigning value to attributs (inherited by 'Healer class' in 'protected' mode--------
    // not possible to access these attributes directly
    
/*  healer.name = "Healer";
    healer.hp = 100;
    healer.dps = 20;
    healer.level = 5;
*/
    // -----------------------------------------------------------------------------------------

    // attribute of 'Healer' class
    healer.healingPower = 10;
    cout << healer.getHealingPower() << endl;
    return 0;
}