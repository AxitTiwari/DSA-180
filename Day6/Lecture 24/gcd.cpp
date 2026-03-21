#include <iostream>

int gcd_(int a, int b) {

    if (a == 0) return b;

    if (b == 0) return a;

    while (a != b) {

        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a;
}

int main() {

    int a = 72, b = 24;

    int gcd = gcd_(a, b);

    std::cout << gcd << std::endl; // 24

    return 0;
}