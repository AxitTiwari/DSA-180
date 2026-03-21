#include <iostream>

int main() {

    int arr[10] = {1, 2, 3};
    int *ptr = &arr[0]; // or just arr

    std::cout << sizeof(arr) << std::endl;

    std::cout << sizeof(ptr) << std::endl;
    std::cout << sizeof(*ptr) << std::endl;

    std::cout << sizeof(&arr) << std::endl;

    // -------------- Address --------------
    int a[10] = {1, 2, 3, 4, 5};

    std::cout << &a << std::endl;
    std::cout << &a[0] << std::endl;
    std::cout << a << std::endl;
    
    return 0;
}