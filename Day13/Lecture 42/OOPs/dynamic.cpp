#include <iostream>

using std::cout;
using std::endl;

class Troop {
public:
    std::string name = "P.E.K.K.A";
    int health = 8000;
    int level = 9;

};

int main() {
    
    // dynamic memory allocation
    Troop* pekka = new Troop;

    cout << "------------------------" << endl;
    cout << "name: " << pekka->name << endl;
    cout << "health: " << pekka->health << endl;
    cout << "level: " << pekka->level << endl;
    cout << "------------------------" << endl;

    pekka->level++;
    pekka->health += 800;

    cout << "------------------------" << endl;
    cout << "name: " << (*pekka).name << endl;
    cout << "health: " << (*pekka).health << endl;
    cout << "level: " << (*pekka).level << endl;
    cout << "------------------------" << endl;

    // cout << "pekka(size): " << sizeof(pekka) << endl;
    // cout << "*pekka(size): " << sizeof(*pekka) << endl;

    return 0;
}