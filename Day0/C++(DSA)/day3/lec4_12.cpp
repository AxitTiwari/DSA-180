#include <iostream>
using namespace std;
int main() {
/*
pattern 13
    A
    B B
    C C C
*/
    int i, j, n;
    cin >> n;
    char ch = 'A';
    i = 1;
    while(i <= n) {
        j = 1;
        while(j <= i) {
            cout << ch << " ";
            j++;
        }
        cout << endl;
        ch = ch + 1;
        i++;
    }
    return 0;
}