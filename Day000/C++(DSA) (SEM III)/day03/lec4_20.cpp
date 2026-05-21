#include <iostream>
using namespace std;
int main() {
/*
pattern 21
        1
       121
      12321
     1234321
     row -> +2
     column -> start -> 1 end -> 1
     row = 1 element = 1
     row = 2 elements = 3
     row = 3 elements = 5
         1
        12
       123
      1234
      2 * 1 = 2 - 1 = 1
      2 * 2 - 1 = 3
      2 * 3 - 1 = 5
*/
    int i, j, n, range;
    cin >> n;
    i = 1;
    while(i <= n) {
        j = 1;
        while(j <= n - i) {
            cout << " ";
            j++;
        }
        j = 1;
        range = 1;
        while(j <= 2 * i - 1) {
            if(j <= i) {
                cout << j;
                j++;
            }
            else {
                cout << j - 2 * range;
                j++;
                range++;
            }
        }
        cout << endl;
        i++;
    }

}