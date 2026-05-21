#include <iostream>

int main() {

    // string methods

    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

/*
    if (name.length() > 12) {
        std::cout << "Your name can not be over 12 charecters." << std::endl;
    }
    else {
        std::cout << "Welcome, " << name << std::endl;
    }

    if (name.empty()) {
        std::cout << "You did not enter your name!" << std::endl;
    }

    name.clear(); // Deletes all characters from the string
    std::cout << "Hello, " << name;

    name.append("@gmail.com");
    std::cout << "Your username is now, " << name << std::endl;
*/

    std::cout << name.at(0) << std::endl;
    name.insert(0, "@");
    std::cout << name << std::endl;

    std::cout << name.find(' ') << std::endl; // index of first occurrence of space

    name.erase(0, 3);
    std::cout << name << std::endl;
    return 0;
}