#include <iostream>
using namespace std;

void reverse(int arr[], int size) {

    int end = size;

    for(int start = 0; start < size / 2; ) {

        int temp = arr[start];
        arr[start++] = arr[--end];
        arr[end] = temp;

    }

}
int main() {
    /*
        Reverse an array:-
    */
   
    int size;
    cout << "Input the size of the array: ";
    cin >> size;

    int arr[20];
    cout << "Input the elements of the array: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    reverse(arr, size);

    cout << "printing the array :-" << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}