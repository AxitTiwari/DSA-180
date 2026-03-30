#include <iostream>
using namespace std;

void update(int arr[], int n) {

    cout  << "Inside the function" << endl;


    // updating the first element of the array
    arr[0] = 120; 

    for(int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Going back to main function" << endl;
}

int main() {
/*
    pass by reference
    - When we pass an array to a function, it is passed by reference.
    - This means that the function can modify the original array.
    - The size of the array is not passed, so we need to pass the size separately
    - The array is passed as a pointer, so we can modify the original array.
    - The function can access the elements of the array using the pointer.
*/
    int arr[3] = {1, 2, 3};

    update(arr, 3);  // <-- passing the address of the first element of the array to the function.

    //printing the array in main function
    for(int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}