#include <iostream>

// initialise the macro
// no extra memory is allocated for it
#define PI 3.14

int main() {

    int radius = 3;

    // macro is not changable
    // PI = PI + 1;

    int area = PI * radius * radius;

    std::cout << area << std::endl;

    return 0;
}