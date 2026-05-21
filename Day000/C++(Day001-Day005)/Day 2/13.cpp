#include <iostream>

int main() {

    // ternary operator

    int grade = 50;
    grade >= 60 ? std::cout << "Pass" : std::cout << "Fail" << std::endl;

    int number = 9;
    number % 2 ? std::cout << "Odd"  << std::endl : std::cout << "Even" << std::endl;

    bool hungry = true;
    // hungry ? std::cout << "You are hungry!" : std::cout << "You are full!";
    std::cout << (hungry ? "You are hungry!" : "You are full!") << std::endl;

    return 0;
}