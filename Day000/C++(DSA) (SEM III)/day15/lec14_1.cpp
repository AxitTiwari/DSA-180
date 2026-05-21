#include <iostream>
using namespace std;

int main() {
    /*
        Find pivot element in an array.
        eg. 
        arr = {6, 7, 9, 1, 2, 3}
        output: 1
    */

    int n;
    cin >> n;

    int arr[20];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //logic
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while(start < end) {
        if(arr[mid] >= arr[0]) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }

    cout << start << endl;

    return 0;
}