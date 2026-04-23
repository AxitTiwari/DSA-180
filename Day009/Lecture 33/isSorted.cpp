#include <iostream>

bool isSorted(int* arr, int size) {

    if (size == 1 || size == 0) return true;
    
    if (arr[0] > arr[1]) return false;

    // reduce the size of the search space
    else {
        bool remainingPart = isSorted(arr+1, size-1);
        return remainingPart;
    }
}

int main() {

    int arr[] = {1, 2, 9, 4, 5};
    int size = 5;

    if (isSorted(arr, size)) {
        std::cout << "Sorted" << std::endl;
    }
    else {
        std::cout << "Not sorted" << std::endl;
    }

    return 0;
}