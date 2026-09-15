#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        vector<vector<int>> temp(n, vector<int>(n));

        // row shift
        for (int i = 0; i < n; i++) {

            int shift = rowShift[i] % n;

            for (int j = 0; j < n; j++) {

                int new_c = (j - shift + n) % n;

                temp[i][new_c] = grid[i][j];
            }
        }

        vector<vector<int>> ans(n, vector<int>(n));

        // col shift
        for (int i = 0; i < n; i++) {

            int shift = colShift[i] % n;

            for (int j = 0; j < n; j++) {

                int new_r = (j - shift + n) % n;

                ans[new_r][i] = temp[j][i];
            }
        }
        return ans;
    }
};