#include <iostream>
using namespace std;
int main() {
/*
pattern 20
    1 1 1 1
      2 2 2
        3 3
          4
*/
    int i, j, n;
    cin >> n;
    i = 1;
    while(i <= n) {
        j = 1;
        //print spaces.
        while(j < i) {
            cout << " ";
            j++;
        }
        j = 1;
        while(j <= n - i + 1) {
            cout << i;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}