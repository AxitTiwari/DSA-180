#include <iostream>

// Global variable -> lifespam -> entire code
int score = 100;

int main() {

    // Global variable for main() function
    int i = 5;

    {
        // local variable -> automatically frees memory (or deleted) outside these brakets
        int i = 2;
        std::cout << i << std::endl;

        std::cout << "score in braket: " << score << std::endl;
    }

    std::cout << i << std::endl;

    std::cout << "score outside braket: " << score << std::endl;

    return 0;
}