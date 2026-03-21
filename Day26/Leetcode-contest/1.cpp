#include <vector>
using namespace std;

class Solution {
private:
    int average(vector<int>& nums, int start) {

        int sum = 0;
        for (int i = start; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum == 0) return 0;

        int totalElements = nums.size() - start;
        return sum / totalElements;
    }
    
public:
    int dominantIndices(vector<int>& nums) {

        // edge cases
        if (nums.size() == 0 || nums.size() == 1) return 0;

        int count = 0;
        for (int i = 0; i < nums.size()-1; i++) {

            int avg = average(nums, i+1);
            if (nums[i] > avg) count++;
        }
        return count;
    }
};