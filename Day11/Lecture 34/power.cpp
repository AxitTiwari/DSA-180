#include <iostream>

// O(logb) -> time complexity

int power(int a, int b) {

    if (b == 0) return 1;

    if (b == 1) return a;

    int ans = power(a, b/2);

    if (b & 1) {
        return a * ans * ans;
    }
    else {
        return ans * ans;
    }
}

int main() {

    int a = 2;
    int b = 10;

    int pow = power(a, b);

    std::cout << pow << std::endl;

    return 0;
}