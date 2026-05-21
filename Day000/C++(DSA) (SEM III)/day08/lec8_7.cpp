#include <iostream>
using namespace std;

int factorial(int n) {

    if(n < 0)
        return -1;

    if(n == 1 || n == 0)
        return 1;

    int result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int nCr(int n, int r) {
    if(n < r) {
        return 0; // Invalid case
    }

    int answer = factorial(n) / (factorial(r) * factorial(n - r));
    return answer;

}

int main() {
    int n, r;
    cin >> n >> r;

    int answer = nCr(n, r);

    cout << "Answer is " << answer << endl;
    return 0;
}