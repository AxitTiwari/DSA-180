#include <iostream>

namespace string {
    std::string str = "Axit";
}

namespace charArr {
    char str[] = "Axit";
}

char toLowercase(char ch) {

    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }

    return ch;
}

bool isPalindrome(char name[], int n) {

    int start = 0, end = n-1;

    while (start < end) {

        if (toLowercase(name[start]) != toLowercase(name[end]))
            return false;
        
        start++;
        end--;
    }

    return true;
}

void reverse(char name[], int size) {

    int start = 0, end = size-1;

    // swap first and last element and so on ..
    while (start < end) {
        std::swap(name[start++], name[end--]);
    }
}

int getLength(char name[]) {

    int length = 0;

    for (int i = 0; name[i] != '\0'; i++) {
        length++;
    }

    return length;
}

int main() {

    char name[20];

    std::cout << "Enter your name: " << std::endl;
    std::cin >> name;

    std::cout << "Your name is " << name << std::endl;

    std::cout << "length of your name " << name << " is " << getLength(name) << std::endl;

    reverse(name, getLength(name));

    std::cout << "Reverse of your name: " << name << std::endl;

    std::cout << "Palindome: " << isPalindrome(name, getLength(name)) << std::endl;

    // ## difference between charecter array and string
    /*
        // std::string str = "Axit";
        std::cout << string::str << " ";

        string::str[2] = '\0';
        std::cout << string::str << " ";

        // char str[] = "Axit";
        std::cout << charArr::str << " ";

        charArr::str[2] = '\0';
        std::cout << charArr::str << " ";
    */

    std::string str = "Axit";
    str[1] = 'B';
    std::cout << str << " ";

    return 0;
}