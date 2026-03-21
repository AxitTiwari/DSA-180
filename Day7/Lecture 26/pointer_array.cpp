#include <iostream>

int main() {

    int a[20] = {1, 2, 3, 4, 5};

    // a = a + 1; // can not change the value of symbol table

    int *p = &a[0];

    std::cout << p << " : " << *p << std::endl;
    p = p + 1;
    std::cout << p << " : " << *p << std::endl;
    
    return 0;
}