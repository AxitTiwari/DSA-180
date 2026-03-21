#include <iostream>
using namespace std;
int main() {
    //pattern 7
    int i, j, n;
    cin >> n;
    i = 1;
    while(i <= n) {
        j = 1;
        while(j <= i) {
            cout << i << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}