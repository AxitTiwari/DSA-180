#include <iostream>

int main() {

    std::string name;
    int age;

    std::cout << "What's your full name? ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "What's your age? ";
    std::cin >> age;

    std::cout << "Hello, " << name << "!" << std::endl;
    return 0;
}