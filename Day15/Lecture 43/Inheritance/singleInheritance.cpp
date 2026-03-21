#include <iostream>

using namespace std;

class Troop {
public:
    string troopName;
    int dps;
    int hp;
    int speed;
    string color;
};

class Healer : public Troop {
public:
    int healtroop;
    int healHero;
};

int main() {

    Healer healer;

    healer.troopName = "Healer";
    healer.dps = 0;
    healer.hp = 2000;
    healer.speed = 10;
    healer.color = "yellow";
    healer.healHero = 40;
    healer.healtroop = 100;
    
    return 0;
}