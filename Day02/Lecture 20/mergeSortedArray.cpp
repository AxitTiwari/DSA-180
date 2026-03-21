#include <iostream>
#include <vector>
#include <array>

void print(int ans[], int size);
void merge(int arr1[], int n, int arr2[], int m, int arr3[]);

int main() {

    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8};
    int arr3[9];

    int n = 5, m = 4;

    print(arr1, 5);
    print(arr2, 4);

    merge(arr1, n, arr2, m, arr3);
    print(arr3, 9);         // 1 2 3 4 5 6 7 8 9 
    
    return 0;
}

void print(int ans[], int size) {

    for (int i = 0; i < size; i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
}

void merge(int arr1[], int n, int arr2[], int m, int arr3[]) {
    
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }

    // left elements of array 1
    while (i < n) {
        arr3[k++] = arr1[i++];
    }

    // left elements of array 2
    while (j < m) {
        arr3[k++] = arr2[j++];
    }
}