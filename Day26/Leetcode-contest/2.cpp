#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        
        vector<long long> result;

        // push first element into the vector
        result.push_back(nums[0]);
        
        if (nums.size() == 0 || nums.size() == 1) return result;

        int iResult = 0;
        for (int i = 1; i < nums.size(); i++) {

            // compaire the element of resultant vector and nums
            if (nums[i] == result[iResult]) {
                result[iResult] = nums[i] * 2;
            }
            else {
                result.push_back(nums[i]);
                iResult++;
            }
        }

        if (result.size() == 0 || result.size() == 1) return result;

        // edge case
        if (result[0] == result[1]) {

            result[0] = result[0] * 2;
            for (int i = 1; i < result.size()-1; i++) {
                result[i] = result[i+1];
            }
            result.pop_back();
        }

        return result;
    }
};