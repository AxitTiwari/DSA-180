#include <iostream>
using namespace std;
int main() {
    // fibonacci series
    // 0 1 1 2 3 5 8 
    int n;
    cin >> n;
    int a = 0, b = 1, next_num;
    cout << a << " " << b << " ";
    for(int i = 2; i < n; i++) {
        next_num = a + b;
        a = b;
        b = next_num;
        cout << b << " ";
    }
    return 0;
}