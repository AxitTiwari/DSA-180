#include <iostream>
using namespace std;

int main() {

    /*
        sort 0 and 1
    */

    int arr[8] = {1, 1, 0, 0, 1, 0, 0, 1};

    int n = 8, i = 0, j = n - 1;
    while(i < j) {
        while(arr[i] == 0 && i < j) {
            i++;
        }
        while(arr[j] == 1 && i < j) {
            j--;
        }
        // ab arr[i] = 1 hoga or arr[j] = 0 hoga to swap kr do dono ko
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}