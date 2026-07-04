// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/2054357494

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int l = 1, r = numbers.size() - 1;
        while (l < r) {

            cout << "hello";

            if (numbers[l] + numbers[r] == target) return {l, r};

            if (numbers[l] + numbers[r] > target) r = r - 1;
            else {
                l = l + 1;
            }
        }
        return {-1, -1};
    }
};