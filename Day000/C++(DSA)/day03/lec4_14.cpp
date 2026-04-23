#include <iostream>
using namespace std;
int main() {
/*
pattern 15
    A
    B C
    C D E
    D E F G
    row -> i->half -> i/2 --> index ->new value -> new row -> first element.
    i = 2 -> i/2 -> 1
*/
    int i, j, n;
    cin >> n;
    i = 0;
    
    while(i < n) {
        j = 0;
        char ch = 'A' + i;
        while(j <= i) {
            //cout << ch << " ";
            cout << ch << " ";
            j++;
            ch = ch + 1;
        }
        cout << endl;
        i++;
    }
    return 0;
}