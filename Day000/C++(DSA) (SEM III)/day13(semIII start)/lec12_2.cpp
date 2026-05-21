#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int k) {
    // 1 2 2 2 2 4 7 <- array
    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    // break the question in two parts , Ist find first occurence of the element
    while(start <= end) {
        if(arr[mid] == k) {
            ans = mid;
            end = mid - 1; // <- left wala part.
        }
        if(arr[mid] > k) {
            end = mid - 1;
        }
        if(arr[mid] < k) {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int k) {
    // 1 2 2 2 2 4 7 <- array
    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    // last occurence.
    while(start <= end) {
        if(arr[mid] == k) {
            ans = mid;
            start = mid + 1; // <- left wala part.
        }
        if(arr[mid] > k) {
            end = mid - 1;
        }
        if(arr[mid] < k) {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main() {
    /*
        First and Last position of an element in sorted array.
    */

    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[20];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int firstO = firstOcc(arr, n, k);
    int lastO = lastOcc(arr, n, k);

    cout << "first and last occrence of " << k << " is as : " << firstO << " and "<< lastO << " respectively" << endl;

    return 0;
}