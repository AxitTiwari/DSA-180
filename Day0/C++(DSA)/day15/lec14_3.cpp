#include <iostream>
using namespace std;

int main() {
    /*
        Find pivot element in an array.
        eg. 
        arr = {6, 7, 9, 1, 2, 3}
        output: 9
    */

    int n;
    cin >> n;

    int k;
    cin >> k;

    int arr[20];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while(start <= end) {
        
        if(arr[mid] == k) {
            cout << "element found in the array in index: " << mid << endl;
            break;
        }

        // In first function
        if(arr[mid] >= arr[0]) {
            if(arr[mid] > k) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        // In 2nd function
        else {
            if(arr[mid] > k) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        mid = start + (end - start) / 2;
    }

    return 0;
}