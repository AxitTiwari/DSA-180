#include <iostream>

bool isPalindrome(std::string str, int i, int j) {

    if (i > j) return true;

    if (str[i] != str[j]) return false;
    else {
        isPalindrome(str, i-1, j-1);
    }
}

int main() {

    std::string name = "abbccbba";

    int i = 0, j = name.length()-1;

    if (isPalindrome(name, i , j)) {
        std::cout << "string is palindrome\n";
    }
    else {
        std::cout << "string is NOT a palindrome\n";
    }

    return 0;
}