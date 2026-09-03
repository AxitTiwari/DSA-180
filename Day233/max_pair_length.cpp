// https://leetcode.com/problems/maximum-length-of-pair-chain/submissions/2129469813

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int count = 0;
        int prev = pairs[0][1];
        for (int i = 1; i < pairs.size(); i++) {
            
            if (prev < pairs[i][0]) {
                prev = pairs[i][1];
                count += 1;
            }
        }
        return count + 1;
    }
};