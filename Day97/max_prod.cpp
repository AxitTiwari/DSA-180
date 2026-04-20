// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/submissions/1983764851

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        priority_queue<int> max_heap;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {

                int prod = (nums[i]-1) * (nums[j]-1);
                max_heap.push(prod);
            }
        }
        return max_heap.top();
    }
};