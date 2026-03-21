#include <iostream>

void printSum(int arr[][3], int m, int n) {

    for (int i = 0; i < m; i++) {

        int sum = 0;
        for (int j = 0; j < n; j++) {

            sum += arr[i][j];
        }
        std::cout << sum << " ";
    }
    std::cout << std::endl;
}

int main() {

    // create 2D Array
    int arr[3][3];

    // taking input -> row-wise
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            std::cin >> arr[row][col]; 
        }
    }

    printSum(arr, 3, 3);

    return 0;
}
