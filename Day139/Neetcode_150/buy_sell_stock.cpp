#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() == 1) return 0;

        int max_profit = 0;

        int left = 0;
        for (int right = 1; right < prices.size(); right++) {

            if (prices[left] > prices[right]) {
                left = right;
                continue;
            }

            max_profit = max(max_profit, prices[right] - prices[left]);
        }
        return max_profit;
    }
};