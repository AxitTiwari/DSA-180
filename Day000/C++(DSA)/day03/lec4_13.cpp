#include <iostream>
using namespace std;
int main() {
/*
pattern 14
    A
    B C
    D E F
    G H I J
    i -> 0
    ch = A + 1 + 0 = B, A + 1 + 1 = C
*/
    int i, j, n;
    char ch = 'A';
    cin >> n;
    i = 0;
    while(i < n) {
        j  = 0;
        while(j <= i) {
            cout << ch << " ";
            ch = ch + 1;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}