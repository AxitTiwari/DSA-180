#include <iostream>

using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal is eating\n";
    }

    void eat(string name) {
        cout << name << " is eating\n";
    }
};

int main() {

    Animal animal;

    animal.eat();

    animal.eat("Elephant");

    return 0;
}