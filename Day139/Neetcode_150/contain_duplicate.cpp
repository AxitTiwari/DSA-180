#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> count;
        for (auto num : nums) {

            if (count[num]) return true;

            count[num]++;
        }
        return false;
    }
};