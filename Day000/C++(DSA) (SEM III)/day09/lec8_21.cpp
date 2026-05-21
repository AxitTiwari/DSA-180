#include <iostream>
using namespace std;

int getMax(int num[], int n) {

    int max = INT32_MIN;

    for(int i = 0; i < n; i++) {
        if(num[i] > max)      // maxi = max(maxi, num[i]) <- inbuilt function to find max of two integers.
            max = num[i];
    }

    return max;

}

int getMin(int num[], int n) {

    int min = INT32_MAX;

    for(int i = 0; i < n; i++) {
        if(num[i] < min)
            min = num[i];
    }

    return min;

}

int main() {
    /*
        max/min element of an array.
    */
{

    int array[10] = {2, 4, 1, 9, 6, 3, 2, 11, 4, 7};

    int max , min;
    max = 0;
    min = 999999;

    for(int i = 0; i < 10; i++) {
        if(max < array[i])
            max = array[i];
        if(min > array[i])
            min = array[i];
    }

    cout << "maxmum element is: " << max << endl;
    cout << "minimum element is: " << min << endl;
    
}

    //initialize the array.
    int size;
    cin >> size;

    int num[100];

    // input the elements.
    for(int i = 0; i < size; i++) {
        cin >> num[i];
    }

    // find max , min
    int max = getMax(num, size);
    int min = getMin(num, size);

    // printing max / min
    cout << "maxmum element is: " << max << endl;
    cout << "minimum element is: " << min << endl;


    return 0;
}