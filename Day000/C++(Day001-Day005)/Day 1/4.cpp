#include <iostream>

int main() {
    const double PI = 3.14159;
    double radius = 10;
    double circumference = 2 * PI * radius;

    // PI = 10; // can not change the value now, its read-only

    std::cout << "Circumference: " << circumference << std::endl;
    return 0;
}