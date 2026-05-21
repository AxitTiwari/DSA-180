#include <iostream>

int main() {

    int *pointer = nullptr;
    int x = 123;

    pointer = &x;

    if (pointer == nullptr) {
        std::cout << "Pointer is not assigned\n";
    }
    else {
        std::cout << "Pointer is assigned\n";
        std::cout << *pointer << std::endl;
    }

    return 0;
}