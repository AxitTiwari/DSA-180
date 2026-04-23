#include <iostream>

int main() {

    int i = 5;

    // ----------create a reference variable----------
    int &j = i;

    std::cout << i << std::endl;
    i++;
    std::cout << i << std::endl;
    j++;
    std::cout << i << std::endl;
    std::cout << j << std::endl;

    return 0;
}