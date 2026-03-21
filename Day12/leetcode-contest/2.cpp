#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        
        // ---------- copy non-negative elements into a space -------------
        vector <int> nonNegative;
        for (int num : nums) {
            if (num >= 0) {
                nonNegative.push_back(num);
            }
        }
        // ---------- --------------------------------------- -------------

        // -------------- rotate this vector by k positions ---------------
        k = k % nonNegative.size();

        vector <int> temp(nonNegative.size());
        for (int i = 0; i < nonNegative.size(); i++) {
            temp[(i+k) % nonNegative.size()] = nonNegative[i];
        }

        nonNegative = temp;
        // -------------- -------------------------------- ----------------

        // ------------ place them onto their right position --------------
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] >= 0) {
                nums[i] = nonNegative[j++];
            }
        }
        return nums;
    }
};