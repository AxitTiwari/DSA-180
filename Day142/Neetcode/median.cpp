// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size();

        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int s = 0, e = n;
        int left = (n + m + 1) / 2;
        while (s <= e) {

            int m1 = s + (e - s) / 2;
            int m2 = left - m1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (m1 < n) r1 = nums1[m1];
            if (m2 < m) r2 = nums2[m2];

            if (m1 - 1 >= 0) l1 = nums1[m1-1];
            if (m2 - 1 >= 0) l2 = nums2[m2-1];

            if (l1 <= r2 && l2 <= r1) return (n + m) % 2 == 0 ? (max(l1, l2) + min(r1, r2)) / (double) 2 : max(l1, l2);

            if (l1 > r2) e = m1 - 1;
            else         s = m1 + 1;
        }
        return -1;
    }
};