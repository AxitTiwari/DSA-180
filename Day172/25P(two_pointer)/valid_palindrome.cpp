// https://leetcode.com/problems/valid-palindrome/submissions/2055290427

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        
        int i = 0, j = s.length() - 1;
        while (i < j) {

            if (!((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= '0' and s[i] <= '9'))) {
                i++;
                continue;
            }

            if (!((s[j] >= 'a' and s[j] <= 'z') or (s[j] >= 'A' and s[j] <= 'Z') or (s[j] >= '0' and s[j] <= '9'))) {
                j--;
                continue;
            }

            if (tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};