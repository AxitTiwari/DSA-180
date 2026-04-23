#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {

        map<int, bool> isBulbOn;

        vector<int> onBulbs;

        for (int bulb : bulbs) {
            isBulbOn[bulb] = !isBulbOn[bulb];
        }

        for (auto it = isBulbOn.begin(); it != isBulbOn.end(); it++) {

            // check key is true
            if (it->second) {
                onBulbs.push_back(it->first);
            }
        }
        return onBulbs;
    }
};