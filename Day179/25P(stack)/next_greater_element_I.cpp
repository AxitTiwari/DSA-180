// https://leetcode.com/problems/next-greater-element-i/submissions/2063641041

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        st.push(-1);

        unordered_map<int, int> mp;
        for (int i = nums2.size()-1; i >= 0; i--) {

            if (st.top() == -1) {
                mp[nums2[i]] = -1;
                st.push(nums2[i]);
            }
            else {

                while (st.top() != -1 && st.top() <= nums2[i]) st.pop();

                mp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
        }

        vector<int> res;
        for (int num : nums1) {

            if (mp.find(num) != mp.end()) {
                res.push_back(mp[num]);
            }
            else {
                res.push_back(-1);
            }
        }
        
        return res;
    }
};