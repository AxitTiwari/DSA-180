#include <iostream>
using namespace std;

int main() {
    // same question as before but by bhaiya's method

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

    int idx = -1;
    while(start < end) {

        if(arr[mid] < arr[mid + 1]) {
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