#include <iostream>

std::string replaceSpaces(std::string &str) {

    std::string temp = "";

    for (int i = 0; i < str.size(); i++) {

        if (str[i] == ' ') {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else {
            temp.push_back(str[i]);
        }
    }

    return temp;
}

int main() {

    std::string name = "My name is khan";

    name = replaceSpaces(name);

    std::cout << name << std::endl;

    return 0;
}