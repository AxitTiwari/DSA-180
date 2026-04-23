#include <iostream>
#include <queue>

using namespace std;

int main() {

    /*
        priority queue - A priority queue is like a queue, but instead of serving elements in FIFO (first-in-first-out) order,
                         it serves them in order of priority.

                         By default in C++, the largest element has the highest priority (max-heap behavior).
        So:
            In a normal queue → first element inserted is first to come out.
            In a priority queue → element with the highest priority (largest value) comes out first.

    */

    // create the priority queue 
    priority_queue<int> maxi; // max heap

    // add elements
    maxi.push(1);
    maxi.push(11);
    maxi.push(9);
    maxi.push(5);

    // size
    cout << "Maxi size " << maxi.size() << endl;

    // print elements
    int n = maxi.size();
    for(int i = 0; i < n; i++) {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;

    cout << "Maxi size after printing " << maxi.size() << endl;

    // mini - heap
    priority_queue<int, vector<int>, greater<int> > mini;

    // add elements
    mini.push(1);
    mini.push(11);
    mini.push(9);
    mini.push(5);

    // size
    cout << "Mini size " << mini.size() << endl;

    // print elements
    int m = mini.size();
    for(int i = 0; i < n; i++) {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;

    cout << "Mini size after printing " << mini.size() << endl;

    cout << "Is empty or not " << mini.empty() << endl;

    return 0;
}