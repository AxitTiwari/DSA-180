#include <iostream>

int main() {

    // create 2D Array
    int arr[3][4];

    // taking input -> row-wise
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            std::cin >> arr[row][col]; 
        }
    }

    // printing
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            std::cout << arr[row][col] << " "; 
        }
        std::cout << std::endl;
    }

    std::cout << "--------------" << std::endl;

    // taking input -> column-wise
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 3; row++) {
            std::cin >> arr[row][col]; 
        }
    }

    // printing
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            std::cout << arr[row][col] << " "; 
        }
        std::cout << std::endl;
    }

    return 0;
}

void print(int arr[][100]) {

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            std::cout << arr[row][col] << " "; 
        }
        std::cout << std::endl;
    }
}

void basics() {
    
    // initialise array with elements: -> row-wise
    int arr1[2][2] = {1, 2, 3, 4};

    // another way
    int arr2[2][2] = {{1, 2}, {3, 4}};
}