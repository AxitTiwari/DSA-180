// https://leetcode.com/contest/biweekly-contest-185/problems/create-grid-with-exactly-one-path/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {

        vector<string> ans;
        for (int i = 0; i < m; i++) {

            string temp;
            for (int j = 0; j < n; j++) {

                if (i == 0 || j == n-1) {
                    temp += '.';
                    continue;
                }
                temp += '#';
            }
            ans.push_back(temp);
        }
        return ans;
    }
};