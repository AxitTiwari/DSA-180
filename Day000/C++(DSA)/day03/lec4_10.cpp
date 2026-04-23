#include <iostream>
using namespace std;
int main() {
/*
pattern 11
    A B C
    D E F 
    G H I   
*/
    int i, j, n;
    char ch  = 'A';
    cin >> n;
    i = 1;
    while(i <= n) {
        j = 1;
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