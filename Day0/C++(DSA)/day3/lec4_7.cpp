#include <iostream>
using namespace std;
int main() {
    // pattern 8.
/*
    1
    2 1
    3 2 1
    4 3 2 1
    5 4 3 2 1
    value -> 1 -> 2 1 -> 3 2 1 -> 4 3 2 1
    1 -> row
    2 -> row
    ..
    4->3->2->1 start -> row -> decrement by 1 but
    problem -> row value -> change  -> cause errors.
    i - j + 1 -> 1 - 1 + 1 = 1, 1 - 2 + 1 -> 0 , 2 - 1 + 1 -> 2 , 2 - 2 + 1 -> 1
*/
    int i, j, n;
    cin >> n;
    i = 1;
    while(i <= n) {
        j = 1;
        int value = i;
        while(j <= i) {
            //cout << value << " ";
            cout << i - j + 1 << " ";
            j++;
            value--;
        }
        cout << endl;
        i++;
    }
    return 0;
}