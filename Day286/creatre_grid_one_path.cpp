// https://leetcode.com/problems/create-grid-with-exactly-one-path/submissions/2182695629

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        
        vector<string> res;
        string tmp(n, '.');
        res.push_back(tmp);

        for (int i = 1; i < m; i++) {

            string row(n, '#');
            row[n-1] = '.';
            
            res.push_back(row);
        }
        return res;
    }
};