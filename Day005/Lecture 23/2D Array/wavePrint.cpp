#include <iostream>
#include <vector>

std::vector <int> wavePrint(std::vector <std::vector <int>> arr, int nRows, int mCols) {

    std::cout << "start->" << std::endl;
    std::vector <int> ans;

    for (int col = 0; col < mCols; col++) {

        // for odd column -> print from bottom to top
        if (col&1) {
            for (int row = nRows-1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        }
        else {
            for (int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }
    std::cout << "end->" << std::endl;
    return ans;
}

int main() {

    int nRows, mCols;
    std::cin >> nRows >> mCols;

    std::vector<std::vector<int>> arr(nRows, std::vector<int>(mCols));

    // input matrix
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < mCols; j++) {
            std::cin >> arr[i][j];
        }
    }

    std::vector<int> result = wavePrint(arr, nRows, mCols);

    // print wave output
    for (int x : result) {
        std::cout << x << " ";
    }

    return 0;
}
