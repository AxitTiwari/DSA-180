// https://leetcode.com/problems/spiral-matrix/submissions/2049741354

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> res;

        int start_r = 0, end_r = n-1;
        int start_c = 0, end_c = m-1;
        while (start_r <= end_r && start_c <= end_c) {

            for (int i = start_c; i <= end_c; i++) {
                res.push_back(matrix[start_r][i]);
            }
            start_r = start_r + 1;

            for (int i = start_r; i <= end_r; i++) {
                res.push_back(matrix[i][end_c]);
            }
            end_c = end_c - 1;

            if (start_r <= end_r) {
                for (int i = end_c; i >= start_c; i--) {
                    res.push_back(matrix[end_r][i]);
                }
                end_r = end_r - 1;
            }

            if (start_c <= end_c) {
                for (int i = end_r; i >= start_r; i--) {
                    res.push_back(matrix[i][start_c]);
                }
                start_c = start_c + 1;
            }
        }
        return res;
    }
};