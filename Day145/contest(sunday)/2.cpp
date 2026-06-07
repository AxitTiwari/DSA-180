#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void f(string &ans, bool prev, int cost, vector<string> &valid, int n, int k) {

        if (cost > k) return;
        
        if (ans.length() == n) {
            valid.push_back(ans);
            return;
        }
        
        ans += '0';
        f(ans, false, cost, valid, n, k);
        ans.pop_back();

        if (prev) return;
        
        ans += '1';
        cost += ans.length() - 1;
        f(ans, true, cost, valid, n, k);
        ans.pop_back();
    }
public:
    vector<string> generateValidStrings(int n, int k) {

        vector<string> valid;
        string ans;
        f(ans, false, 0, valid, n, k);
        return valid;
    }
};