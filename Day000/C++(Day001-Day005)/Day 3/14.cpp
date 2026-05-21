#include <iostream>

// last day 
int main() {

    /*
        && -> Logical AND
        || -> Logical OR
        !  -> Logical NOT
    */
   
    int temp;
    bool sunny = true;

    std::cout << "Enter the temperature: ";
    std::cin >> temp;

    if (temp > 0 && temp < 30) {
        std::cout << "The temperature is good." << std::endl;
    }
    else {
        std::cout << "The temperature is bad." << std::endl;
    }

    if (sunny) {
        std::cout << "It is sunny outside.";
    }
    else {
        std::cout << "It is cloudy outside.";
    }

    return 0;
}