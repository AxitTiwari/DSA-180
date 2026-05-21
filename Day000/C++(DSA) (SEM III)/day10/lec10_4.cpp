#include <iostream>
using namespace std;

void printArr(int arr[], int n){

    for(int i = 0; i < n; i++) {

        cout << arr[i] << " ";

    }
    cout << endl;

}
int main() {
    /*
        find unique(leetcode 1207)  (my solution beats 25% of the solutions))
        eg.
        i/p = {1, 1, 1, 2, 3, 4, 3, 4, 5};
        counting of each digit -> 1 - 3
                                  2 - 1
                                  3 - 2
                                  4 - 2
                                  5 - 1
        not unique counting .

        arr[0] = 1 -> 1 .... 5
    */

    int n;
    cout << "Input the size of the array: ";
    cin >> n;

    int arr[20];
    cout << "Input the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    printArr(arr, n);

    // count no of times each digit occured in the array.
    int countDigit[20];
    int k = 0;
    for(int i = 0; i < n; i++) {
        int count = 1;
        if(arr[i] != '@') {
            for(int j = i + 1; j < n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                    arr[j] = '@';
                }
            }
            if(count) {
                countDigit[k++] = count;
                // arr[i] = '@';
            }
        }
    }

    //count the uniqueness of the digits.
    int duplicate;
    for(int i = 0; i < k; i++) {
        duplicate = 0;
        for(int j = i + 1; j < k; j++) {
            if(countDigit[i] == countDigit[j]) {
                duplicate = 1;
                break;
            }
        }
        if(duplicate) {
            break;
        }
    }

    if(duplicate) {
        cout << "counting is not unique" << endl;
    }
    else {
        cout << "Counting is unique" << endl;
    }

    printArr(countDigit, k);

    return 0;

}