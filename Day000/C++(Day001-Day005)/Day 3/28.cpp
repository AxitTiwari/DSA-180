#include <iostream>

int main() {

    // memory address = a location in memory where data is stored

    std::string name = "Axit Tiwari";
    int age = 19;
    bool student = true;

    std::cout << &name << '\n';
    std::cout << &age << '\n';
    std::cout << &student << '\n';
    
    return 0;
}