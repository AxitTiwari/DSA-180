#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {

        vector<vector<int>> ans;

        unordered_set<int> seen;

        int j = 0;
        for (int i = 0; i < series1.size(); i++) {

            while (j < series2.size() and series1[i][0] > series2[j][0]) j++;

            int val2 = (j == series2.size()) ? 0 : series2[j][1];

            ans.push_back({series1[i][0], series1[i][1] + val2});
            seen.insert(series1[i][0]);
        }

        int i = 0;
        for (int j = 0; j < series2.size(); j++) {

            while (i < series1.size() and series2[j][0] > series1[i][0]) i++;

            if (seen.find(series2[j][0]) != seen.end()) continue;

            int val2 = (i == series1.size()) ? 0 : series1[i][1];

            ans.push_back({series2[j][0], series2[j][1] + val2});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};