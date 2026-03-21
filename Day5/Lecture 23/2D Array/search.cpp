#include <iostream>

bool isPresent(int arr[][4], int target, int m, int n) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == target) return true;
        }
    }

    return false;
}

int main() {

    // create 2D Array
    int arr[3][4];

    // taking input -> row-wise
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            std::cin >> arr[row][col]; 
        }
    }

    int target;
    std::cout << "Enter element to search: ";
    std::cin >> target;

    if (isPresent(arr, target, 3, 4)) {
        std::cout << "Found" << std::endl;
    }
    else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}
