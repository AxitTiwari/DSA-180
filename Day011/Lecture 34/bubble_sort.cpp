#include <iostream>

void sortArray(int* arr, int n) {

    if (n == 0 || n == 1) return;

    for (int i = 0; i < n - 1; i++) {

        if (arr[i] > arr[i+1]) {
            std::swap(arr[i], arr[i+1]);
        }
    }

    sortArray(arr, n-1);
}

int main() {

    int arr[] = {1, 8, 3, 9, 2, 6};

    sortArray(arr, 6);

    for (int i = 0; i < 6; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}