#include <iostream>
using namespace std;
int main() {
/*
pattern 9
    A A A
    B B B
    C C C
*/
    int i, j, n;
    char ch = 'A';
    cin >> n;
    i = 1;
    while(i <= n) {
        j = 1;
        while(j <= n) {
            cout << ch << " ";
            j++;
        }
        cout << endl;
        ch = ch + 1;
        i++;
    }
    return 0;
}