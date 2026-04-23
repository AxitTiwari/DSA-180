#include <iostream>
using namespace std;

int main() {
    /*
        find duplicates in an array.
        eg.
        size = 6
        elements = [1, n-1]
        arr = {1, 2, 3, 4, 5, 3} <- n-1 elements. (1 element twice)

        1        =  001
        2        =  010
        1 XNOR 2 =  100 = 4
        1 XOR  2 =  011 = 3
        3        =  011
        4        =  100
        3 XOR 4  =  111 = 7
        3 XOR 4  =  110 = 6

        1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 3 ^ 1 ^ 2 ^ 3 ^ 4 ^ 5 = 3 
        intitial arr(with one duplicate) ^ array of 1 to n - 1 elements

    */

    // o(n^2)

    int n;
    cout << "Input the size of the array: ";
    cin >> n;

    int arr[20];
    cout << "Input the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // XOR all the elements of the array
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }

    //XOR answer with new created array [1, n-1]
    for(int i = 1; i < n; i++) {
        ans = ans ^ i;
    }

    cout << "ans is: " << ans << endl;

    return 0;
}