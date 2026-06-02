#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> prefix;
        int prod = 1;
        for (int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            prefix.push_back(prod);
        }

        vector<int> suffix(nums.size());
        prod = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            prod *= nums[i];
            suffix[i] = prod;
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {

            int left = i == 0 ? 1 : prefix[i-1];
            int right = i == nums.size()-1 ? 1 : suffix[i+1];
            ans.push_back(left * right);
        }
        return ans;
    }
};