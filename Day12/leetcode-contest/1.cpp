#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {

        int len = nums.size() - 1;
        
        int i = len;
        int j = len -  1;

        int cnt;
        while (i >= 0 && j >= 0) {

            if (nums[i] > nums[j]) {
                i--;
                j--;
            }
            else {
                cnt = j;
                break;
            }
        }

        cnt += 1;

        return cnt;
    }
};