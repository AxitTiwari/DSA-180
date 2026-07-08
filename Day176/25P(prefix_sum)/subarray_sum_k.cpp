// https://leetcode.com/problems/subarray-sum-equals-k/submissions/2060168868

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        int sum = 0, res = 0;
        for (int &num : nums) {
            sum += num;

            if (mp.find(sum-k) != mp.end()) {
                res += mp[sum-k];
            }
            mp[sum] = mp.find(sum) != mp.end() ? mp[sum] + 1 : 1;
        }
        return res;
    }
};