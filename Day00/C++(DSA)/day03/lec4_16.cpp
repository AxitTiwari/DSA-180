#include <iostream>
using namespace std;
int main() {
/*
pattern 17
        *
       **
      ***
     ****
*/
    int i, j, n;
    cin >> n;
    i = 1;
    while(i <= n) {
        j = 1;
        while(j <= n) {
            //print spaces.
            while(j <= n - i) {
                cout << " ";
                j++;
            }
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}