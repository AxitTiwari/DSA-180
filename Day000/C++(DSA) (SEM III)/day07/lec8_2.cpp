#include <iostream>
int main() {
    /*
        calculator
    */
    int a , b;
    char opr;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;
    std::cout << "Enter the operation you want to perform(+,-,*,/): ";
    std::cin >> opr;
    switch(opr) {
        case '+':
            std::cout << "Sum = " << a + b << std::endl;
            break;

        case '-':
            std::cout << "Difference = " << a - b << std::endl;
            break;

        case '*':
            std::cout << "Product = " << a * b << std::endl;
            break;

        case '/':
            if(b != 0) {
                std::cout << "Quotient = " << a / b << std::endl;
            } else {
                std::cout << "Division by zero is not allowed." << std::endl;
            }
            break;
            
        default:
            std::cout << "Invalid operation." << std::endl;
            break;
    }
    return 0;
}