#include <iostream>
using namespace std;

int leftCount(int arr[], int n, int k) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    int count = 0;
    while(start <= end) {
        if(arr[mid] == k) {
            count = mid;
            end = mid - 1;
        }
        if(arr[mid] > k) {
            end = mid - 1;
        }
        if(arr[mid] < k) {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return count;
}

int rightCount(int arr[], int n, int k) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    int count;
    while(start <= end) {
        if(arr[mid] == k) {
            count = mid;
            start = mid + 1;
        }
        if(arr[mid] > k) {
            end = mid - 1;
        }
        if(arr[mid] < k) {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return count;
}

int main() {
    /*
        total number of occurence of a digit , by binary search
    */

    int n;
    cin >> n;
    int k;
    cin >> k;

    int arr[20];
    if(n > 20) {
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int lCount = leftCount(arr, n, k);
    int rCount = rightCount(arr, n, k);
    // -1 to avoid duplicate case if number exits
    int totalCount = rCount - lCount + 1;

    cout << "total number of occurence of " << k << " is/are: " << totalCount << endl;
    return 0;
}