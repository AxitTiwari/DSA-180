#include <iostream>
using namespace std;
int main() {
    // Sum of numbers from 1 to n (only even).
    int n, i, sum;
    cin >> n;
    i = 2;
    sum = 0;
    while(i <= n) {
        sum = sum + i;
        i = i + 2;
    }
    cout << "Sum of N numbers (only even) : " << sum << endl;
    return 0;
}