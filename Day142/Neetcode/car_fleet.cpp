// https://leetcode.com/problems/car-fleet/submissions/2021800301

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        unordered_map<int, int> speed_of_car;
        for (int i = 0; i < position.size(); i++) {
            speed_of_car[position[i]] = speed[i];
        }

        sort(position.rbegin(), position.rend());

        vector<double> stack;
        for (int i = 0; i < position.size(); i++) {

            int pos = position[i];
            double x = (target - pos) / (double)speed_of_car[pos];

            cout << x << endl;

            stack.push_back(x);

            if (stack.size() >= 2 && stack.back() <= stack[stack.size()-2]) {
                stack.pop_back();
            }
        }
        return stack.size();
    }
};