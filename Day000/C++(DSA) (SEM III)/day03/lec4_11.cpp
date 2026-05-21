#include <iostream>
using namespace std;
int main() {
/*
pattern 12
    A B C
    B C D
    E F G
*/
    int i, j, n;
    char ch = 'A';
    cin >> n;
    i = 0;
    while(i < n) {
        j = 0;
        ch = 'A' + i;
        while(j < n) {
            cout << ch << " ";
            ch = ch + 1;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}