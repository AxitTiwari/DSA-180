// yr ye brute force hai or tle de raha hai so work on this.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWidth(vector<int>& planks) {

        int res = 0;
        for (int i = 0; i < planks.size(); i++) {

            for (int k = 0; k < planks.size(); k++) {

                int target = i == k ? planks[i] : planks[i] + planks[k];
                unordered_map<int, int> have;
    
                int pairs = 0;
                for (int j = 0; j < planks.size(); j++) {
    
                    if (target == planks[j]) {
                        pairs++; 
                    }

                    else if (have.find(target-planks[j]) != have.end()) {
                        pairs++;
                        have[target-planks[j]]--;

                        if (have[target-planks[j]] == 0) have.erase(target-planks[j]);
                    }
                    else
                        have[planks[j]]++;
                }
                res = max(res, pairs);
            }
        }
        return res;
    }
};