#include <bits/stdc++.h>
using namespace std;

// 2784 check if array is good

class Solution {
public:
    bool isGood(vector<int>& nums) {
        
        int maxi = INT_MIN;
        unordered_map<int, int> num_appered;
        for (int num : nums) {
            num_appered[num]++;
            maxi = max(maxi, num);
        }

        for (int i = 1; i <= maxi; i++) {
            if (!num_appered[i]) return false;
        }

        if (num_appered[maxi] != 2) return false;

        return maxi + 1 == nums.size() ? true : false;
    }
};