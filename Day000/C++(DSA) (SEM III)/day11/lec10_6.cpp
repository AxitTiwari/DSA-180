#include <iostream>
using namespace std;

int main() {
    /*
        H.W

        Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

        You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

 

        Example 1:

        Input: nums = [4,3,2,7,8,2,3,1]
        Output: [2,3]
        Example 2:

        Input: nums = [1,1,2]
        Output: [1]
        Example 3:

        Input: nums = [1]
        Output: []
    */

    int n;
    cout << "Input the size of the array: ";
    cin >> n;

    int arr[20];
    cout << "Input the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int duplicate[20];
    int k = 0;
    for(int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1;
        if(arr[index] > 0) {
            // cout << "arr[arr[i] - 1] = " << arr[index] << endl;
            // cout << "i = " << i << endl;
            arr[index] = -arr[index];
        }
        else {
            //already a negative number so store it
            // cout << "arr[i] = " << arr[i] << endl;
            // cout << "i = " << i << endl;
            duplicate[k++] = abs(arr[i]);
        }
    }

    cout << "Duplicate elements are: ";
    for(int i = 0; i < k; i++) {
        cout << duplicate[i] << " ";
    }
    cout << endl;

    return 0;
}