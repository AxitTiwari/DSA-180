#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        
        int n = q.size();
        
        if (k > n) return q;
        
        stack<int> s;
        
        // #1 push first k elements into the STACK
        for (int i = 0; i < k; i++) {
            
            int val = q.front();
            q.pop();
            s.push(val);
        }
        
        // #2 pop from stack and push into queue
        while (!s.empty()) {
            
            int val = s.top();
            s.pop();
            q.push(val);
        }
        
        // #3 pop first (n-k) elements from queue and push them into queue
        for (int i = 0; i < n-k; i++) {
            
            int val = q.front();
            q.pop();
            q.push(val);
        }
        return q;
    }
};