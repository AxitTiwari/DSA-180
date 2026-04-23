#include <iostream>

int factorial(int number) {

    // base case
    if (number == 1 || number == 0) return 1;

    int nextNumber = number - 1;

    return number * factorial(nextNumber);
}

int power(int number, int pow) {

    if (pow == 0) return 1;

    return number * power(number, --pow);
}

void reverseCounting(int number) {

    if (number == 0) return;

    std::cout << number << std::endl;

    reverseCounting(--number);
}

void counting(int number) {

    if (number == 0) return;

    counting(--number);

    std::cout << number << std::endl;
}

int main() {

    int num = 5;

    // ---------- factorial ------------
    int facNum = factorial(num);

    std::cout << facNum << std::endl;

    // ---------- power ------------
    int powNum = power(num, 5);

    std::cout << powNum << std::endl;

    // --------- counting --------------
    reverseCounting(num);

    counting(num);

    return 0;
}