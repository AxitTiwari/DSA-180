// https://leetcode.com/problems/different-ways-to-add-parentheses/submissions/2018102852

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int a, int b, char opr) {

        if (opr == '+') {
            return a + b;
        }

        if (opr == '-') {
            return a - b;
        }

        if (opr == '*') {
            return a * b;
        }
        return 0;
    }

    vector<int> f(int s, int e, string &exp) {

        vector<int> result;
        bool is_num = true;

        for (int i = s; i < e; i++) {

            if (!isdigit(exp[i])) {

                is_num = false;

                vector<int> left = f(s, i-1, exp);
                vector<int> right = f(i+1, e, exp);

                for (int x : left) {
                    for (int y : right) {

                        int val = solve(x, y, exp[i]);
                        result.push_back(val);
                    }
                }
            }
        }
        
        if (is_num) result.push_back(stoi(exp.substr(s, e - s + 1)));
        return result;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        
        return f(0, expression.length(), expression);
    }
};