// https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1979752863

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        std::priority_queue <int, std::vector<int>, std::greater<int>> min_heap;

        // store k elements in the heap
        for (int i = 0; i < k; i++) {
            min_heap.push(nums[i]);
        }

        // rest n - k elements, check if element is grater than top of heap
        for (int i = k; i < nums.size(); i++) {

            if (nums[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        return min_heap.top();
    }
};