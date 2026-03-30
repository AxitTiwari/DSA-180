#include <iostream>
using namespace std;

int main() {

    /*
        Selection sort - unstable algorithm.
    */

    int size;
    cin >> size;

    int arr[20];
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < size - 1; i++) {

        int min_index = i;
        for(int j = i + 1; j < size; j++) {

            if(arr[min_index] > arr[j]) {

                min_index = j;
            }
        }

        if(arr[i] > arr[min_index]) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}