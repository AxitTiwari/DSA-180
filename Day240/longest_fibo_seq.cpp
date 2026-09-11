// https://leetcode.com/submissions/detail/2137212152/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        int n = arr.size();

        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }
        
        int maxi = INT_MIN;
        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                int length = solve(j, k, arr);

                maxi = max(maxi, length);
            }
        }
        return maxi == 2 ? 0 : maxi;
    }
private:
    unordered_map<int, int> mp;
    int solve(int j, int k, vector<int>& arr) {

        int a = arr[k] - arr[j];

        if (mp.count(a) && mp[a] < j) {
            return solve(mp[a], j, arr) + 1;
        }
        return 2;
    }
};