#include <iostream>

using namespace std;

class Animal {
public:
    string animalName;

    void move() {
        cout << "Animal is moving\n";
    }
};

class Dog{
public:
    string dogName;

    void move() {
        cout << "Dog is moving\n";
    }
};

class GermanShefard : public Dog, public Animal{
public:

    void move() {
        cout << "jimmy is moving\n";
    }
};

int main() {

    GermanShefard dog;

    dog.dogName = "jimmy";
    dog.move();

    // Inheritance ambiguity resolution -> solution: scope resolution operator
    dog.Animal::move();
    dog.Dog::move();

    return 0;
}