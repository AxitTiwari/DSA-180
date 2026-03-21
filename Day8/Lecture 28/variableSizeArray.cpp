#include <iostream>

int getSum(int* arr, int n) {

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {

    int n;
    std::cin >> n;

    // -----------create a array of dynamic size----------
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int sum = getSum(arr, n);

    std::cout << sum << std::endl;

    return 0;
}