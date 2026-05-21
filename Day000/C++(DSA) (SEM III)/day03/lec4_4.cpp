#include <iostream>
using namespace std;
int main() {
    // pattern 6
    int i, j, n;
    cin >> n;
    i = 0;
    while(i < n) {
        j = 0;
        while(j <= i) {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}