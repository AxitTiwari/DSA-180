#include <iostream>

int largestRowSum(int arr[][3], int m, int n) {

    int max = INT8_MIN;
    int rowIndex = -1;

    for (int i = 0; i < m; i++) {

        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
        
        if (sum > max) {
            max = sum;
            rowIndex = i;
        }
    }

    std::cout << max << std::endl;

    return rowIndex;
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

    int idx = largestRowSum(arr, 3, 3);
    std::cout << idx << std::endl;

    return 0;
}
