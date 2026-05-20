// https://leetcode.com/submissions/detail/2006860443/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size(); ) {

            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }
            else if (nums1[i] > nums2[j]) {
                j++;
            }
            else {
                i++;
            }
        }
        return -1;
    }
};