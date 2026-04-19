// https://leetcode.com/problems/maximum-subarray/submissions/1982769963 

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int kadanes_algorithm(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            
            sum += nums[i];

            maxi = max(maxi, sum);

            // if sum becomes negative -> reset
            if (sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
public:
    int maxSubArray(vector<int>& arr) {

        return kadanes_algorithm(arr);
        
        // priority_queue<int> max_heap;

        // for (int i = 0; i < arr.size(); i++) {

        //     int sum = 0;
        //     for (int j = i; j < arr.size(); j++) {

        //         sum += arr[j];

        //         max_heap.push(sum);
        //     }
        // }
        // return max_heap.top();
    }
};