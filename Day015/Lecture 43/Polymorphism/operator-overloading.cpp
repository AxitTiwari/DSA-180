#include <iostream>

using namespace std;

class Animal {
public:
    string name;

    // overloading +
    string operator+ (Animal &animal) {
        cout << "Adding in procees...\n";
        cout << this->name << " " << animal.name;
        cout << "\nAdding completed\n";
        return this->name +  " " + animal.name;
    }

    // overloading brakets
    void operator() () {
        cout << "\nI am braket-> " << this->name << endl;
    }

    // overloading scope resolution operator(::) -> not possible
    // void operator:: () {
    //     cout << "I am not possible\n";
    // }
};

int main() {

    Animal animal1;
    animal1.name = "elephant";

    Animal animal2;
    animal2.name = "tiger";

    string name = animal1 + animal2;

    cout << "\nname: " << name;

    animal1();

    return 0;
}