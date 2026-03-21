#include <iostream>

int main() {

    // -------------- Address --------------
    int a[10] = {1, 2, 3, 4, 5};

    // a = a + 1; // error

    std::cout << &a << std::endl;
    std::cout << &a[0] << std::endl;
    std::cout << a << std::endl;

    std::cout << "--------------------" << std::endl;

    int *p = &a[0];
    std::cout << p << std::endl;
    std::cout << &p << std::endl;
    std::cout << *p << std::endl;
    
    return 0;
}