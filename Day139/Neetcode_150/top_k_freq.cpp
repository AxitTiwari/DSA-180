#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> count;
        for (auto num : nums) {
           count[num]++;
        }

        vector<vector<int>> freq(nums.size()+1);
        for (auto &[num, cnt] : count) {
            freq[cnt].push_back(num);
        }

        vector<int> ans;
        for (int i = freq.size()-1; i >= 0; i--) {

            for (auto n : freq[i]) {

                if (ans.size() < k) {
                    ans.push_back(n);
                }
            }
        }
        return ans;
    }
};