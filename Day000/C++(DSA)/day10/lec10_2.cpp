#include <iostream>
using namespace std;

int findUnique(int arr[], int n) {

    for(int i = 0; i < n; i++) {

        int count = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j] == arr[i]) {
                count++;
            }
        }

        if(count == 1) {
            return arr[i];
        }
    }

    return -1;

}
int main() {
    /*
        Find unique.

        by my way
    */

    int n;
    cout << "Input the size of the array: ";
    cin >> n;

    int arr[20];
    cout << "Input elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int num = findUnique(arr, n);

    if(num != -1) {
        cout << "Unique number is : " << num << endl;
    }

    return 0;

}