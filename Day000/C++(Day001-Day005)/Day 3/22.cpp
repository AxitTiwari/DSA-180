#include <iostream>

std::string concatStrings(std::string str1, std::string str2);

int main() {

    std::string firstName = "Bro";
    std::string lastName = "Code";

    std::string fullName = concatStrings(firstName, lastName);

    std::cout << fullName << std::endl;
    
    return 0;
} 

std::string concatStrings(std::string str1, std::string str2) {
    return str1 + " " + str2;
}

