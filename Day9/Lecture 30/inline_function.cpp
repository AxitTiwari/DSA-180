#include <iostream>

//compiler is not using any extra space.
// during compilation every function call is replaced by its one line body.
inline int getMax(int& a, int& b) {
    return a > b ? a : b;
}

int main() {

    int a = 5, b = 2;

    int ans = getMax(a, b);

    std::cout << ans << std::endl;

    return 0;
}