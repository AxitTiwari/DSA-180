// https://leetcode.com/problems/sliding-window-maximum/submissions/1985519772

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> give_answer(vector<int>& nums, int k) {

        // deque<int> dq;
        priority_queue<pair<int, int>> max_heap;

        vector<int> ans;

        // first window
        for (int i = 0; i < k; i++) {
            // dq.push_back(nums[i]);

            max_heap.push({nums[i], i});
        }
        ans.push_back(max_heap.top().first);
        
        if (max_heap.top().second == 0) max_heap.pop();

        // all remaing windows
        for (int i = k; i < nums.size() ; i++) {

            while (!max_heap.empty() && max_heap.top().second < i-k+1) {
                max_heap.pop();
            }

            // dq.pop_front();
            // dq.push_back(nums[i]);

            max_heap.push({nums[i], i});

            ans.push_back(max_heap.top().first);
        }
        return ans;
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        return give_answer(nums, k);
        
        // priority_queue<int> max_heap;

        // vector<int> ans;
        // for (int i = 0; i <= nums.size()-k; i++) {
        //     for (int j = i; j < i + k && j < nums.size(); j++) {
                
        //         if (max_heap.empty()) max_heap.push(nums[j]);
        //         else {

        //             if (max_heap.top() < nums[j]) {
        //                 max_heap.pop();
        //                 max_heap.push(nums[j]);
        //             }
        //         }
        //     }
        //     ans.push_back(max_heap.top());
        //     max_heap.pop();
        // }
        // return ans;
    }
};