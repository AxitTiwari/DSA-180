// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/submissions/2008366741

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        vector<int> ans;
        int count = 0;
        unordered_map<int, bool> mp;
        for (int i = 0; i < A.size(); i++) {
            
            int count = 0;
            mp[A[i]] = true;
            for (int j = 0; j <= i; j++) {
                if (mp[B[j]]) {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};