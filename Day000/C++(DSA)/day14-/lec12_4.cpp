#include <iostream>
using namespace std;


int Find_largest_left(int arr[], int n) {

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    int idx = -1;
    int ans = INT32_MIN;
    while(start <= end) {
        
        if(mid != n - 1) {
            if(arr[mid] == arr[mid + 1]) {
                if(arr[mid] > ans) {
                    ans = arr[mid];
                    idx = mid;
                }
                end = mid - 1;
            }
            if(arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            }
            if(arr[mid] > arr[mid + 1]) {
                if(arr[mid] > ans) {
                    ans = arr[mid];
                    idx = mid;
                }
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
    }
    return idx;
}

int Find_largest_right(int arr[], int n) {

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    int idx = -1;
    int ans = INT32_MIN;
    while(start <= end) {
        
        if(mid != n - 1) {
            if(arr[mid] == arr[mid + 1]) {
                if(arr[mid] > ans) {
                    ans = arr[mid];
                    idx = mid;
                }
                start = mid + 1;
            }
            if(arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            }
            if(arr[mid] > arr[mid + 1]) {
                if(arr[mid] > ans) {
                    ans = arr[mid];
                    idx = mid;
                }
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
    }
    return idx;
}


int main() {

    /*
    Peak index in a mountain array(852)
    You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

    Return the index of the peak element.

    Your task is to solve it in O(log(n)) time complexity.
    */
    int n;
    cin >> n;

    int arr[20];
    if(n > 20) {
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int Largest_left = Find_largest_left(arr, n);
    int Largest_right = Find_largest_right(arr, n);

    int ans = (arr[Largest_left] > arr[Largest_right]) ? Largest_left : Largest_right;
    
    cout << ans << endl;

    return 0;
}