#include <iostream>

void happyBirthday(std::string name);

int main() {

    // function
    
    std::string name = "Moon";

    happyBirthday(name);

    return 0;
} 

void happyBirthday(std::string name) {
    std::cout << "Happy Birthday to " << name << std::endl;
    std::cout << "Happy Birthday to " << name << std::endl;
    std::cout << "Happy Birthday dear " << name << "!" << std::endl;
    std::cout << "Happy Birthday to " << name << std::endl;
}

