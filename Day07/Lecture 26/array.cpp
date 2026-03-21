#include <iostream>

int getSum(int arr[], int n) {

    // this arr[] <- is not an array , instead it is a pointer
    std::cout << "size of arr(in getSum function, when passed as argument): " << sizeof(arr) << std::endl; // size of arr(in getSum function, when passed as argument): 4

    return 1;

}

int main() {

    int arr[5] = {0}; // 5 * 4 = 20 bytes

    std::cout << "size of array(arr): " << sizeof(arr) << std::endl;

    getSum(arr, 5);

    return 0;
}