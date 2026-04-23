#include <iostream>
using namespace std;

int main() {
/*
    Arrays -> derieved data structure 
    -> similar type of items.
    -> memory stored in contigous location
    -> assessed using index

    why?
    To store multiple same type of value in a single variable.

    declaration
    int dost[10];

    Initialiazation
    int number[3] = {5, 7 , 11};

    int arr[10000] = {0}; <-- all values initialized with 0.
    ______________________
    |1|2|3|4|5|6|7|8|9|10|
    ----------------------

    address :-
    base address = 100 
    100 -> 104 -> 108 -> 112 -> .......
    100 + 1 * sizeof(int)

    Assess :-
    Array[index] = value
    dost[0] = 1;
    dost[1] = 2;
    dost[2] = 3;
    .
    .
    .
    dost[9] = 10;
*/
    float arr[10];

    for(int i = 1; i < 3; i++)  
        cin >> arr[i];

    for(int i = 1; i < 3; i++)  
        cout << arr[i] << endl;
}