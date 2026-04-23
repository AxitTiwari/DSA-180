#include <iostream>

class Hero {

    int health;
};

int main() {
    
    Hero h1;

    std::cout << "size: " << sizeof(h1) << std::endl;

    return 0;
}