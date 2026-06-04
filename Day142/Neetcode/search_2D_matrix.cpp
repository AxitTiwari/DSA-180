// https://leetcode.com/problems/search-a-2d-matrix/submissions/1889066127

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();
        
        int s = 0, e = row * col - 1;
        while (s <= e) {

            int m = s + (e - s) / 2;

            int i = m / col;
            int j = m % col;

            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                e = m - 1;
            }
            else {
                s = m + 1;
            }
        }
        return false;
    }
};