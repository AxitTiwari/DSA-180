#include <iostream>

void print(int *arr, int& size, int start = 0) {

    for (int i = start; i < size; i++) {
        std::cout << i[arr] << " ";
    }
    std::cout << std::endl;
}

int main() {

    int arr[] = {1, 2, 3, 4};
    int size = 4;

    print(arr, size);

    print(arr, size, 2);

    return 0;
}