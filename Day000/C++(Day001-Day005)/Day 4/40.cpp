#include <iostream>

class Animal {
    public:
        bool alive = true;

        void eat() {
            std::cout << "This animal is eating\n";
        }
};

class Dog : public Animal {
    public:

        void bark() {
            std::cout << "Woof woof\n";
        }
};

int main() {
    Dog dog1;

    std::cout << dog1.alive << std::endl;
    dog1.eat();
    dog1.bark();

    return 0;
}