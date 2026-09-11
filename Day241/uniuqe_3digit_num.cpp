// https://leetcode.com/problems/unique-3-digit-even-numbers/submissions/2138444018

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        vector<int> used(digits.size(), 0);
        string num;
        return f(num, used, digits);
    }
private:
    unordered_set<string> seen;
    int f(string num, vector<int>& used, vector<int>& digits) {

        if (num.length() == 3) {

            cout << num << endl;

            // for (int n : num) {
            //     cout << n;
            // }
            // cout << endl;

            // cout << num.back() << endl;

            if (num[0] == '0') return 0;

            // int digit = num[2];

            if (seen.find(num) != seen.end()) return 0;

            if (num.back() == '2' || num.back() == '4' || num.back() == '6' || num.back() == '8' || num.back() == '0') {
                // cout << "1";
                seen.insert(num);
                return 1;
            }

            // cout << "yes" ;
            return 0;
        }

        int res = 0;
        for (int idx = 0; idx < digits.size(); idx++) {

            if (used[idx] != 0) continue;

            used[idx] = 1;
            num.push_back('0' + digits[idx]);

            // cout << num << endl;
            res += f(num, used, digits);
            // cout << res << endl;
            num.pop_back();
            used[idx] = 0;
        }

        // cout << "res: " << res << endl;
        return res;
    }
};