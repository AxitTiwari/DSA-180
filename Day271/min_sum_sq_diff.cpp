// https://leetcode.com/submissions/detail/2170409805/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        int size = 1e5;
        vector<int> cnt(size+1, 0);
        for (int i = 0; i < nums1.size(); i++) {

            int diff = abs(nums1[i] - nums2[i]);
            cnt[diff] += 1;
        }

        int k = k1 + k2;
        for (int i = size; i > 0 && k > 0; i--) {

            if (cnt[i] == 0) continue;

            int diff = i;

            int count_opr = min(cnt[i], k);
            cnt[diff] -= count_opr;
            cnt[diff-1] += count_opr;
            k -= count_opr;
        }

        long long min_sum = 0;
        for (int i = size; i > 0; i--) {

            if (cnt[i] == 0) continue;

            min_sum += 1LL * cnt[i] * i * i;
        }
        return min_sum;
    }
};