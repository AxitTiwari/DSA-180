// https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int res = 0;
        
        int s = 0, e = height.size() - 1;
        while (s < e) {

            res = max(
                res, 
                min(height[s], height[e]) * (e - s)
            );

            if (height[s] < height[e]) {
                s++;
            }
            else {
                e--;
            }
        }
        return res;
    }
};