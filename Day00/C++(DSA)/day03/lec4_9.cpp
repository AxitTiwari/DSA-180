#include <iostream>
using namespace std;
int main() {
/*
pattern 10
    A B C
    A B C 
    A B C
*/
    int i, j, n;
    char ch = 'A';
    cin >> n;
    i = 1;
    while(i <= n) {
        j = 1;
        ch = 'A';
        while(j <= n) {
            cout << ch << " ";
            ch = ch + 1;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}