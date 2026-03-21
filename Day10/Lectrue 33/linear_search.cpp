#include <iostream>

bool isPresent(int* arr, int size, int target) {

    if (size == 0) return false;

    if (arr[0] == target) return true;
    else {
        return isPresent(arr+1, size-1, target);
    }
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    if (isPresent(arr, size, 5)) {
        std::cout << "present";
    }
    else {
        std::cout << "not present";
    }

    return 0;
}