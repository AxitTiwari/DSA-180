#include <iostream>
using namespace std;
int main() {
    //pattern
    int i, j;
    i = j = 0;
    while(i < 4) {
        j = 0;
        while(j < 4) {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}