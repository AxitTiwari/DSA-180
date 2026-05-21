#include <iostream>
using namespace std;
int main() {
    //pattern 5.
    int i, j, n;
    cin >> n;
    i = j = 0;
    while(i < n) {
        j = 0;
        // j-> 1 + 3 = 4 , j -> 2 + 3 = 5 , i -> 3 , j -> 1 + 3 * i(=2) =7 
        while(j < n) {
            cout << j + n * i + 1 << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}