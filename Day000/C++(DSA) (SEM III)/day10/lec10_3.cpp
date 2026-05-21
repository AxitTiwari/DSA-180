#include <iostream>
using namespace std;

int findUnique(int *arr, int size) {

    int ans = 0;
    for(int i = 0; i < size; i++) {
        ans = ans ^ arr[i];   // 0 ^ a = a. 0 ^ 0 = 0
    }
    
    return ans;
}

int main() {
    /*
        find unique.
        - by bhaiya's method.

        eg.
        n = 5
        arr = {1, 2, 1, 2, 8}
        1 ^ 2
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

    cout << "Unique number is : " << num << endl;

    return 0;
}