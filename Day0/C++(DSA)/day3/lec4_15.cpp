#include <iostream>
using namespace std;
int main() {
/*
pattern 16
    D
    C D
    B C D
    A B C D
*/
    int i, j, n;
    cin >> n;
    char ch = 'A';
    i = 1;
    ch = ch + n - 1;
    while(i <= n) {
        j = 1;
        while(j <= i) {
            cout << ch << " ";
            ch = ch + 1;
            j++;
        }
        cout << endl;
        i++;
        ch = ch - i;
    }
    return 0;
}