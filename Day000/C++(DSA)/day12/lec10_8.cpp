#include <iostream>
using namespace std;

int main() {
/*
    pair sum
    you are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.
*/

    int n;
    cin >> n;

    int s;
    cin >> s;

    int arr[20];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == s) {
                cout << min(arr[i], arr[j]) << " " << max(arr[i], arr[j]) << endl;
            }
        }
    }

    return 0;
}