#include <iostream>

int countWaysToClimb(int n) {

    if (n < 0) return 0;
    if (n == 0) return 1;

    int ans = countWaysToClimb(n-1) + countWaysToClimb(n-2);

    return ans;
}

int main() {

    int n = 5;

    int ans = countWaysToClimb(n);

    std::cout << ans << std::endl;

    return 0;
}