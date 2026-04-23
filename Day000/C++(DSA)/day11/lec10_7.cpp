#include <iostream>
using namespace std;

int main() {
/*
    Intersection of Two Arrays 
    array - sorted non decreasing order.
    a size - m
    b size - n
    a = {1, 2, 3};
    b = {3, 4, 5, 6};
*/

    int m, n;
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;

    int arr1[20], arr2[20];
    cout << "Enter elements of the first array(a): ";
    for(int i = 0; i < m; i++) {
        cin >> arr1[i];
    }
    cout << "Enter elements of the secand array(b): ";
    for(int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    //print intersection

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(arr1[i] == arr2[j]) {
                cout << arr2[j] << " ";
                arr2[j] = INT32_MIN;
                break;
            }
        }
    }

    return 0;
}