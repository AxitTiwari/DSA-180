#include <iostream>
using namespace std;
int main() {
    // sum of numbers from 1 to n;
    int n, sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << "sum = " << sum << endl;
}