#include <iostream>

int main() {

    // ---------- create a 2D Array -------------------
    int n, m;
    std::cin >> n >> m;

    // ----- Defination -------
    int** arr = new int* [n];
    for (int i = 0; i < m; i++) {
        arr[i] = new int [m];
    }
    // ------------------------

    // ---------input----------
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            std::cin >> arr[i][j];
        }
    }

    // --------print----------
    std::cout << "--------print----------" << std::endl;
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // ----------------------

    // ---------------------------------------------

    return 0;
}