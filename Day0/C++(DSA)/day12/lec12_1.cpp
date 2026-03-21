#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    while(start <= end) {
        if(arr[mid] == key) {
            return mid;
        }
        if(key > arr[mid]) {
            start = mid + 1;
        }
        if(key < arr[mid]) {
            end = mid - 1;
        }

        mid = start + (end - start) / 2; // To avoid overflow
    }
    return -1;
}

int main() {
/*
    Binary Search
    - monotonic function -> element shouldbe in monotonic order.
*/

    int even[] = {2, 4, 6, 8, 12, 18};
    int odd[] = {3, 8, 11, 14, 16};

    int index = binarySearch(even, 6, 12);

    cout << " Index of 12 is: " << index << endl;

    return 0;
}