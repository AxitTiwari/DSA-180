#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(2*n);

        for (int i = 0, j = 2*n-1; i < n && j >= 0; i++, j--) {
            ans[i] = nums[i];
            ans[j] = nums[i];
        }
        return ans;
    }
};