#include <iostream>
using namespace std;

int main() {

    /*
        Insetion sort - stable algorithm
    */

    int n;
    cin >> n;

    int arr[20];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++) {

        int current_element = arr[i];
        int j;
        for(j = i - 1; j >= 0; j--) {

            if(current_element < arr[j]) {
                arr[j + 1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j + 1] = current_element;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}