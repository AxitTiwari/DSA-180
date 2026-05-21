#include <iostream>
#include <algorithm> 
using namespace std;

int main() {

    /*
        Bubble sort. - stable algorithm
        An in-place sort is a sorting algorithm that does not require extra significant memory to sort the data — it rearranges elements within the original data structure.

    Key Points:

        Uses O(1) or constant extra space (apart from a few variables for swapping or indexing).
        Modifies the original array/vector directly.
        No extra copy of the data is created.
        Examples: Bubble Sort, Selection Sort, Insertion Sort, Heap Sort.
    */

    int n;
    cin >> n;

    int arr[20];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {

        bool swaped = false;
        for(int j = 0; j < n - i - 1; j++) {

            if(arr[j] > arr[j + 1]) {

                swap(arr[j], arr[j + 1]);
                swaped = true;
            }
        }

        if(!swaped)
            break;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}