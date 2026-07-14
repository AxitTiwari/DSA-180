// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/submissions/2067679648

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int min(int a, int b) {return a < b ? a : b;}

public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> min_heap;
        for (int i = 0; i < min(nums1.size(), k); i++) {
            min_heap.push({nums1[i] + nums2[0], i, 0});
        }

        vector<vector<int>> res;
        while (k > 0 and !min_heap.empty()) {

            auto [sum, i, j] = min_heap.top();
            min_heap.pop();

            res.push_back({nums1[i], nums2[j]});
            k--;

            if (j+1 < nums2.size()) {
                min_heap.push({nums1[i] + nums2[j+1], i, j+1});
            }
        }
        return res;
    }
};