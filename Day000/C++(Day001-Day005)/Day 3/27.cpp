#include <iostream>

int main() {

    // fill() = assign a value to a range of elements

    std::string foods[10];
    fill(foods, foods + 10, "Pizza");

    for (std::string food: foods) {
        std::cout << food << '\n';
    }
    
    return 0;
}