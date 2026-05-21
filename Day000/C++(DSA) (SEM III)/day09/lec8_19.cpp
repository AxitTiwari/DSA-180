#include <iostream>
using namespace std;

void printArray(int arr[], int n) {

    cout << "Printing the array: " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    /*
        pass by refrence.
    */
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int sizeArr = sizeof(arr) / sizeof(int);  // size can be calculated

    cout << "size is(arr): " << sizeArr << endl;

    int arr2[10] = {1, 2};

    printArray(arr2, 10);

    int sizeArr2 = sizeof(arr2) / sizeof(int); // but if array contains just 2 elements with size 10 bytes then we can not found the size.

    cout << endl << "size is(arr2): " << sizeArr2 << endl;


    // printArray(arr, 10);
}