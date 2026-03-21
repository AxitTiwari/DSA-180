#include <iostream>

using namespace std;

class Animal {
public:
    void speak() {
        cout << "speaking..\n";
    }
};

class Dog: public Animal {
public:
    void speak() {
        cout << "woof!..\n";
    }
};

int main() {

    Dog dog;

    dog.speak();

    return 0;
}