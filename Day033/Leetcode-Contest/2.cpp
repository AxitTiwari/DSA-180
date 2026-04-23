#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {

        // 20,20,10,30,30,30
        
        // push element with their frequency
        unordered_map<int, int> elementCount;
        for (int num : nums) {
            elementCount[num]++;
        }

        // 20 -> 2
        // 10 -> 1
        // 30 -> 3

        // push freq with their frequency
        unordered_map<int, int> freqCount;
        for (auto it : elementCount) {
            freqCount[it.second]++;
        }

        // 2 -> 1
        // 1 -> 1
        // 3 -> 1

        // return first unique frequency
        for (int num : nums) {

            if (freqCount[elementCount[num]] == 1) {
                return num;
            }
        }
        return -1;
    }
};