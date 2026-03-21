#include <iostream>

int main() {

    int n, m;
    std::cin >> n >> m;

    int** arr = new int* [n];
    for (int i = 0; i < m; i++) {
        arr[i] = new int [m];
    }
    
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            std::cin >> arr[i][j];
        }
    }

    std::cout << "--------print----------" << std::endl;
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // ---------------- release the memory ---------------
    for (int i = 0; i < n; i++) {
        delete [] arr[i];
    }
    delete []arr;
    // ---------------------------------------------------

    std::cout << "--------print----------" << std::endl;
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}