// https://leetcode.com/problems/generate-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> dfs(string s, int opened, int closed, int n)
    {
        vector<string> res;

        if (opened == n && closed == n)
        {
            res.push_back(s);
            return res;
        }

        if (opened < n)
            for (const auto & elem : dfs(s + "(", opened + 1, closed, n))
                res.push_back(elem);
        
        if (closed < opened)
            for (const auto & elem : dfs(s + ")", opened, closed + 1, n))
                res.push_back(elem);

        return res;
    }

    vector<string> generateParenthesis(int n) {
        return dfs("", 0, 0, n);
    }
};