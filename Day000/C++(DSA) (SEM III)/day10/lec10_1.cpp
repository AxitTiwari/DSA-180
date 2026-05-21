#include <iostream>
using namespace std;

void swapAlternate(int arr[], int n) {

    for(int i = 0; i < n; ) {
        if(i + 1 < n) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        i = i + 2;
    }

}

int main() {

    /*
        8th or 9th lecture mix ho gai hai , esiliye yaha se  direct 10th lecturte start hai.

        1 Problem :- swap alternate
        eg. i/p = {1, 2, 7, 8, 5}
        o/p = {2, 1, 8, 7, 5}
    */

    int n;
    cout << "Input the size of the array: ";
    cin >> n;

    int arr[20];
    cout << "Input elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    swapAlternate(arr, n);

    cout << "Printing the final array: " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

}