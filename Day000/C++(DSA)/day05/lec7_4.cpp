#include <iostream>
using namespace std;
int main() {
/*
    compliment by bhaiya
    input n
    ~n
    create a mask so that ~n & mask = required answer.
    n = 5 -> 0000....00101
    ~n    = 1111.....11010
    mask = 0000......00111
    answer = 0000....00101
*/
    int n;
    cin >> n;
    int mask = 0;

    //edge case
    if(n == 0)
        return 1;
    while(n != 0) {
        mask = (mask << 1) | 1;
        n = n >> 1;
    }
    int ans = ((~n) & mask);
    cout << "mask = " << mask << endl;
    cout << "ans = " << ans << endl;
    return 0;
}