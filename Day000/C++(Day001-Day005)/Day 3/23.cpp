#include <iostream>

void bakePizza();
void bakePizza(std::string topping);
void bakePizza(std::string topping1, std::string topping2);

int main() {

    bakePizza();
    bakePizza("pepperoni");
    bakePizza("pepperoni", "mushrooms");
    return 0;
}

void bakePizza() {
    std::cout << "Here is your pizza!" << std::endl;
}

void bakePizza(std::string topping) {
    std::cout << "Here is your pizza with " << topping << "!" << std::endl;
}

void bakePizza(std::string topping1, std::string topping2) {
    std::cout << "Here is your pizza with " << topping1 << " and " << topping2 << "!" << std::endl;
}


