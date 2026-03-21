#include <iostream>

void sayNumber(std::string numbers[], int num) {

    if (num == 0) return;

    int lastDigit = num % 10;

    sayNumber(numbers, num/10);

    std::cout << numbers[lastDigit] << " ";
}

int main() {

    int num = 412;

    std::string numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    sayNumber(numbers, num);
    std::cout << std::endl;

    return 0;
}