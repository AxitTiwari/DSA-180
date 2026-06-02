#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int idx1 = 0;
        int idx2 = numbers.size()-1;
        while (idx1 < idx2) {

            if (numbers[idx1] + numbers[idx2] == target) return {idx1+1, idx2+1};
            else 
                if (numbers[idx1] + numbers[idx2] > target) idx2--;
            else
                idx1++;
        }
        return {};
    }
};