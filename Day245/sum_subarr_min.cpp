// https://leetcode.com/problems/sum-of-subarray-minimums/submissions/2142870754

#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int> pse = previousSmaller(arr);
        vector<int> nse = nextSmaller(arr);

        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {

            int left = i - pse[i], right = nse[i] - i;
            long long contribute = (left * right * 1LL * arr[i]) % MOD;
            sum = (sum + contribute) % MOD;
        }
        return sum;
       
    }
private:
    vector<int> previousSmaller(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n);

        stack<int> st; // stores indices

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> nextSmaller(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n);

        stack<int> st; // stores indices

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return ans;
    }
};