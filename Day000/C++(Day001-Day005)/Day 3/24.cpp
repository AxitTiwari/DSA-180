#include <iostream>

int main() {
     
    // array = a data structure that can hold multiple values

    std::string cars[] = {"BMW", "Audi", "Ford"};

    std::cout << cars << std::endl;
    std::cout << cars[0] << std::endl;
    std::cout << cars[1] << std::endl;
    std::cout << cars[2] << std::endl;

    double prices[] = {2, 3.4, 6, 7.5};
    std::cout << prices[0] << std::endl;
    std::cout << prices[1] << std::endl;
    std::cout << prices[2] << std::endl;

    return 0;
}
