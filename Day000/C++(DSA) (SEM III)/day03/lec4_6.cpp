#include <iostream>
using namespace std;
int main() {
    // pattern 7
    int i, j, n, cnt;
    cin >> n;
    i = 1;
    while(i <= n) {
        j = 0;
        while(j < i) {
            cout << i + j << " ";
            j++;
            cnt++;
        }
        cout << endl;
        i++;
    }
    return 0;
}