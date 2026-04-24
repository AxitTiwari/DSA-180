// https://leetcode.com/problems/top-k-frequent-elements/submissions/1987181494

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // need two DS -> Map + Heap, for O(n),
        
        // [1,1,1,2,2,3]
        /*
            1 : 3
            2 : 2
            3 : 1
        */

        unordered_map<int, int> map_num_count;
        for (int num : nums) {

            map_num_count[num]++;
        }

        priority_queue <pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> min_heap;
        for (auto it : map_num_count) {
            
            if (min_heap.size() < k) {
                min_heap.push({it.second, it.first}); // (freq, num)
            }
            else {

                if (min_heap.top().first < it.second) {
                    min_heap.pop();
                    min_heap.push({it.second, it.first});
                }
            }
        }

        vector<int> ans;
        while (!min_heap.empty()) {
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};