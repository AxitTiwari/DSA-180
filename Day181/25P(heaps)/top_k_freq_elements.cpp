// https://leetcode.com/problems/top-k-frequent-elements/submissions/2066284247

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> count;
        for (auto &num : nums) {
            count[num] += 1;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (auto &it : count) {
            min_heap.push({it.second, it.first});

            if (min_heap.size() > k) min_heap.pop();
        }
        
        vector<int> res;
        while (!min_heap.empty()) {

            auto [cnt, num] = min_heap.top();
            min_heap.pop();

            res.push_back(num);
        }
        return res;
    }
};