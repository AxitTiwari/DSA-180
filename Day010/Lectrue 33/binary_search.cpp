#include <iostream>

bool binarySearch(int* arr, int s, int e, int k) {

    if (s > e) return false;

    int mid = s + (e - s) / 2;

    if (arr[mid] == k) return true;
    
    if (arr[mid] < k) {
        return binarySearch(arr, mid+1, e, k);
    }
    else {
        return binarySearch(arr, s, mid-1, k);
    }
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int s = 0, e = 4;

    if (binarySearch(arr, s, e, 8)) {
        std::cout << "present";
    }
    else {
        std::cout << "not present";
    }

    return 0;
}