#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {

        vector<int> answer;
        for (int i = 0; i < nums.size(); i++) {

            int num = nums[i];
            bool is_odd = num & 1 ? true : false;

            int count = 0;
            for (int j = i+1; j < nums.size(); j++) {

                if (is_odd) {

                    if (!(nums[j] & 1)) {
                        count++;
                    }
                }
                else {
                    if (nums[j] & 1) {
                        count++;
                    }
                }
            }
            answer.push_back(count);
        }
        return answer;
    }
};