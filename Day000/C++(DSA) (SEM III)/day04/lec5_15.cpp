#include <iostream>
using namespace std;
int main() {
/*
    leetcode questions 
    1. Subtract the product and Sum of Digits of an integer(1281)
    eg. n = 234
    p = 2 * 3 * 4 = 24
    s = 2 + 3 + 4 = 9
    ans = p - s = 24 - 9 = 15
*/
    int n, sum = 0, product = 1;
    cin >> n;
    int copy_n = n;
    while(n) {
        int rem = n % 10; // extract last digit
        sum += rem;
        n = n / 10; // updation
    }
    while(copy_n) {
        int rem = copy_n % 10; // extract last digit
        product *= rem;
        copy_n = copy_n / 10; // updation
    }
    int answer = product - sum;
    cout << product << " " << sum << endl;
    cout << answer << endl;
    return 0;
}