// https://leetcode.com/submissions/detail/2169796758/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        
        int res = 0;
        for (int i = 0; i < nums.size(); i++) if (nums.size() % (i+1) == 0) res += nums[i] * nums[i];
        return res;
    }
};