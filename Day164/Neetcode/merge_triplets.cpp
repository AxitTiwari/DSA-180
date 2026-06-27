// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/submissions/2046364285

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        unordered_set<int> good;

        for (auto t : triplets) {

            // remove rows with value greater than in target
            if (t[0] > target[0] or t[1] > target[1] or t[2] > target[2]) continue;

            int i = 0;
            for (int v : t) {

                if (target[i] == v) good.insert(i);
                i++;
            }
        }

        return good.size() == 3;
    }
};