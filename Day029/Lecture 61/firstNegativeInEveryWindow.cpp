#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        
        deque<int> dq;
        vector<int> ans;
        
        // -------first window---------
        for (int i = 0; i < k; i++) {
            
            // push -ve number indices into the deck
            if (arr[i] < 0) {
                dq.push_back(i);
            }
        }
        
        // store the results;
        if (dq.size() > 0) {
            ans.push_back(arr[dq.front()]);
        }
        else {
            ans.push_back(0);
        }
        
        // -------for rest window--------
        for (int i = k; i < arr.size(); i++) {
            
            // pop old element if not in window
            if (!dq.empty() && (i-dq.front() >= k)) {
                dq.pop_front();
            }
            
            // push new element's index if negative
            if (arr[i] < 0) {
                dq.push_back(i);
            }
            
            // store the results;
            if (!dq.empty()) {
                ans.push_back(arr[dq.front()]);
            }
            else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};