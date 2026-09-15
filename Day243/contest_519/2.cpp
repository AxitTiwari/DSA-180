#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long shadowPairs(vector<int>& nums) {

        long long ans = 0;

        // monotonic stack
        vector<int> st;

        for (int x : nums) {

            ans += lower_bound(st.begin(), st.end(), x) - st.begin();

            while (!st.empty() and st.back() > x) {
                st.pop_back();
            }

            st.push_back(x);
        }
        return ans;
    }
};