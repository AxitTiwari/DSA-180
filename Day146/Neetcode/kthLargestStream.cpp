// https://leetcode.com/problems/kth-largest-element-in-a-stream/submissions/2026287910

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k_;

    KthLargest(int k, vector<int>& nums) {

        k_ = k;
        
        for (int i = 0; i < nums.size(); i++) {

            if (pq.size() < k) {
                pq.push(nums[i]);
            }
            else {

                if (pq.top() < nums[i]) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {

        if (pq.empty()) {
            pq.push(val);
        }
        else if (pq.size() < k_) {
            pq.push(val);
        }
        else {
            if (pq.top() < val) {
                pq.pop();
                pq.push(val);
            }
        }

        return pq.top();
    }
};
