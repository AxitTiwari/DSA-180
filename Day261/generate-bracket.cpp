// https://leetcode.com/submissions/detail/2159881730/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        string str;
        solve(0, 0, n, str);

        return res;
    }
private:
    vector<string> res;
    void solve(int count_open, int count_close, int n, string& para) {

        if (count_open < count_close || count_open > n) return;

        if (count_open + count_close == 2 * n) {
            res.push_back(para);
            return;
        }

        para.push_back('(');
        solve(count_open+1, count_close, n, para);
        para.pop_back();

        para.push_back(')');
        solve(count_open, count_close+1, n, para);
        para.pop_back();
    }
};