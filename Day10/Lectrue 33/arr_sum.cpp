#include <iostream>

int findSum(int* arr, int size) {

    if (size == 0) return 0;

    if (size == 1) return arr[0];

    int sum = arr[0] + findSum((arr+1), size-1);

    return sum;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    int sum = findSum(arr, size);

    std::cout << sum << std::endl;

    return 0;
}