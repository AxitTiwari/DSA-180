#include <iostream>

int main() {

    int arr[10] = {1, 2, 3};

    std::cout << "Address of first memory block: " << arr << std::endl;

    std::cout << "Value at 0th location: " << *arr << std::endl;
    std::cout << "Value at 1st location: " << *(arr+1) << std::endl;

    int i = 2;
    std::cout << i[arr] << std::endl;
    std::cout << arr[i] << std::endl;

    return 0;
}