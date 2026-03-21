#include <iostream>

// To modify the original variable inside a function
void update(int& a) {
    a = 1000;
}

int main() {

    int a = 10;

    std::cout << a << std::endl;
    update(a);
    std::cout << a << std::endl;

    return 0;
}