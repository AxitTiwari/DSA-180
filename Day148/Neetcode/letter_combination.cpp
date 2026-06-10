// https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/2028611785

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return res;
        
        string digit;
        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(0, digit, digits, mapping);
        return res;
    }
private:
    void dfs(int i, string &digit, string &digits, string mapping[]) {

        if (i == digits.length()) {
            res.push_back(digit);
            return;
        }

        for (char ch : mapping[digits[i]-'0']) {
            digit.push_back(ch);
            dfs(i+1, digit, digits, mapping);
            digit.pop_back();
        }
    }

};