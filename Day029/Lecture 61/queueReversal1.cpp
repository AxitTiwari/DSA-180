#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        
        stack<int> s;
        
        // pop values from queue and push them onto the stack
        while (!q.empty()) {
            int val = q.front();
            q.pop();
            s.push(val);
        }
        
        while (!s.empty()) {
            int val = s.top();
            q.push(val);
            s.pop();
        }
    }
};