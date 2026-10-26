#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStaircase(vector<int>& nums) {

        int n = nums.size();
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {

            unordered_map<int, int> freq;
            unordered_map<int, int> rank;

            int distinct = 0, bad = 0;
            for (int j = i; j < nums.size(); j++) {

                // new element
                if (rank.find(nums[j]) == rank.end()) {
                    rank[nums[j]] = ++distinct;
                    bad += 1;
                }

                if (freq[nums[j]] != rank[nums[j]]) bad--;

                freq[nums[j]]++;

                if (freq[nums[j]] != rank[nums[j]]) bad++;

                if (bad == 0) res++;
            }
        }
        return res;
    }
};