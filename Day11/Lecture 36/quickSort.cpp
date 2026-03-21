#include <iostream>

int partition(int* arr, int s, int e) {

    int pivot = arr[s];

    // count how many elements are less than 'pivot' element
    int cnt = 0;
    for (int i = s+1; i <= e; i++) {

        if (arr[i] <= pivot) cnt++;
    }

    // place pivot at right position
    int pivotIndex = s + cnt;
    std::swap(arr[pivotIndex], arr[s]);

    // place correct element at left and right part of pivot element
    int i = s, j = e;
    while (i  < pivotIndex && j > pivotIndex) {

        while (arr[i] <= arr[pivotIndex]) i++;

        while (arr[j] > arr[pivotIndex]) j--;

        if (i  < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }

    std::cout << "pivotindex: " << pivotIndex << "\n";
    for (int i = s; i <= e; i++) {
        std::cout << arr[i] << " ";
    } std::cout << std::endl;

    return pivotIndex;
}

void quickSort(int* arr, int s, int e) {

    // base case
    if (s >= e) return;

    // partition
    int p = partition(arr, s, e);

    // left part sort karo
    quickSort(arr, s, p-1);

    // right part sort karo
    quickSort(arr, p+1, e);
}

int main() {

    int arr[] = {3, 5, 1, 8, 2, 4};
    int size = 6;

    quickSort(arr, 0, 5);

    std::cout << "-----------------\n";
    for (int i = 0; i < 6; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << "-----------------\n";

    return 0;
}