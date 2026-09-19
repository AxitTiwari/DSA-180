// https://leetcode.com/problems/sum-of-subarray-ranges/submissions/2146370923

#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:

    long long solve(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }

private:
    long long sumSubarrayMins(vector<int>& arr) {
        
        vector<int> pse = previousSmaller(arr);
        vector<int> nse = nextSmaller(arr);

        long long sum = 0;
        for (int i = 0; i < arr.size(); i++) {

            int left = i - pse[i], right = nse[i] - i;
            long long contribute = left * right * 1LL * arr[i];
            sum = sum + contribute;
        }
        return sum;
       
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        
        vector<int> pge = prevGreater(arr);
        vector<int> nge = nextGreater(arr);

        long long sum = 0;
        for (int i = 0; i < arr.size(); i++) {

            int left = i - pge[i], right = nge[i] - i;
            long long contribute = left * right * 1LL * arr[i];
            sum = sum + contribute;
        }
        return sum;
       
    }

    vector<int> nextGreater(vector<int>& nums) {

        stack<int> st;

        int n = nums.size();

        vector<int> ans(n);
        for (int i = n-1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return ans;
    }

    vector<int> prevGreater(vector<int>& nums) {
        
        stack<int> st;
        st.push(-1);

        int n = nums.size();

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {

            while (!st.empty() && st.top() != -1 && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return ans;
    }

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

class Solution {
private:
    MySolution obj;
public:
    long long subArrayRanges(vector<int>& nums) {

        return obj.solve(nums);
    }
};