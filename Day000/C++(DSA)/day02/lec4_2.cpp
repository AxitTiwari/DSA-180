#include <iostream>
using namespace std;
int main() {
    //pattern 4.
    int i, j, n;
    cin >> n;
    i = j = 1;
    while(i <= n) {
        j = 1;
        while(j <= n) {
            cout << " " << n - j + 1;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}