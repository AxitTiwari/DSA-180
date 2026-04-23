#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<int> s;
    int mini;

    public:
        
    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        }
        else {

            if (data < mini) {
                int val = 2 * data - mini;
                s.push(val);
                mini = data;
            }
            else {
                s.push(data);
            }
        }
    }

    void pop() {
        
        if (s.empty()) {
            return;
        }

        int curr = s.top();
        s.pop();

        if (curr < mini) {

            int prevMini = mini;
            int val = 2 * mini - curr;
            mini = val;
        }
    }

    int top() {
        
        if (s.empty()) return -1;

        int curr = s.top();
        if (curr < mini) {
            return mini;
        }
        else {
            return curr;
        }
    }

    int getMin() {

        if (s.empty()) return -1;
        
        return mini;
    }  
};