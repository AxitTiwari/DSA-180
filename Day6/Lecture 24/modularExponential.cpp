#include <iostream>

// Fast Exponential
int modularExponential(int x, int n, int m) {

    int res = 1;

    while (n > 0) {

        // odd 
        if (n & 1) {
            res = ((res%m) * (x%m)) % m;
        }
        x = ((x%m) * (x%m)) % m;

        // divide by 2;
        n = n >> 1;
    }
    return res;
}

int main() {

    // (x ^ n ) % m

    int x = 2, n = 8, m = 3;

    int ans = modularExponential(x, n, m);

    std::cout << ans << std::endl; // 1

    return 0;
}