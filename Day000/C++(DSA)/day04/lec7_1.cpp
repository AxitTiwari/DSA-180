#include <iostream>
using namespace std;
int main() {
/*
    leetcode question
    3. Reverse integer
*/
    int n;
    cin >> n;
    int num = 0;
    int found = 0;
    while(n) {
        int rem = n % 10;
        //IF NOT IN RANGE THEN RETURN 0
        if(num > INT32_MAX /10 || num < INT32_MIN / 10) {
            found = 1;
            break;
        }
        num = 10 * num + rem;
        n = n / 10;
    }
    if(found == 0) 
        cout << num << endl;
    return 0;
}