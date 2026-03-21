#include <iostream>
using namespace std;

int main() {
    /*
        print sum of all elements of an array.
    */
    int n;
    cout << "Input the size of the array: ";
    cin >> n;

    // input elements.
    int arr[n];
    cout << "Input elements : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //sum of elements.
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    cout << "Sum of elements of the array is : " << sum << endl;

    return 0;

}