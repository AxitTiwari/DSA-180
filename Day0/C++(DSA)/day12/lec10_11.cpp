#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

int main() {

    /*
        sort 0 , 1 and 2
    */

    int arr[9] = {0, 2, 2, 1, 0, 1, 1, 0, 2};

    int n = 9, i = 0, j = n - 1;

    int prev = INT32_MIN;
    while(prev != i) {

        prev = i;
        
        // increment i
        cout << i << endl;
        while(arr[i] == 0 && i < j) {
            i++;
        }

        // decrement j
        while(arr[j] == 2 && i < j) {
            j--;
        }

        //eske bad arr[i] ya to 1 ya to 2 pr point kr raha hoga 
        // or arr[j] ya to 0 ya to 1 pr point kr raha hoga

        // 1st condition :- if arr[i] == 2 and arr[j] == 0 -> swap
        while(arr[i] == 2 && arr[j] == 0 && i < j) {
            swap(arr[i], arr[j]);
            // printArr(arr, n);
            i++;
            j--;
        }

        // 2nd condition :-
        if(arr[i] == 1) {
            int k = i;
            while(arr[k] == 1 && k < j) {
                k++;
                // 2nd condion :- i)
                if(arr[k] == 2 && k < j) {
                    swap(arr[k], arr[j]);
                    // printArr(arr, n);
                    k++;
                    j--;
                }
                // 2nd condition :- ii)
                if(arr[k] == 0 && k < j) {
                    swap(arr[k], arr[i]);
                    printArr(arr, n);
                    k++;
                    i++;
                }
            }
        }

        // 3rd condition
        if(arr[i] == 2) {
            swap(arr[i], arr[j]);
            // printArr(arr, n);
            j--;
        }
        
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}