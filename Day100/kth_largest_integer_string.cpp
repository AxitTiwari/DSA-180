// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/submissions/1986007709

#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(string& a, string& b) {

        if (a.size() == b.size()) {
            return a > b;
        }
        return a.size() > b.size();
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue <string, vector<string>, cmp> min_heap;

        for (string n : nums) {

            min_heap.push(n);

            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        return min_heap.top();
    }
};