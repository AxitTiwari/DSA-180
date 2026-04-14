// https://leetcode.com/problems/lemonade-change/submissions/1978227214

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        unordered_map<int, int> avilable_cash;
        for (int bill : bills) {

            if (bill == 5) {
                avilable_cash[5]++;
            }
            else if (bill == 10) {

                if (avilable_cash[5] < 1) return false;

                avilable_cash[5] -= 1;
                avilable_cash[10] += 1;
            }
            else {

                if (!avilable_cash[10] && !avilable_cash[5]) return false;
                else if (avilable_cash[10] && !avilable_cash[5]){
                    return false;
                }
                else if (avilable_cash[10] && avilable_cash[5]) {
                    avilable_cash[10]--;
                    avilable_cash[5]--;
                }
                else if (!avilable_cash[10] && avilable_cash[5]) {

                    for (int i = 1; i <= 3; i++) {
                        if (!avilable_cash[5]) return false;
                        else {
                            avilable_cash[5]--;
                        }
                    }
                }
            }
        }
        return true;
    }
};