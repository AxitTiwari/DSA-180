#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string str) {

        int s = 0, e = str.length()-1;

        while (s < e) {

            while (s < str.length() && !isalnum(str[s])) s++;
            while (e >= 0 && !isalnum(str[e])) e--;

            if (s < e && tolower(str[e]) != tolower(str[s])) return false;
            s++;
            e--;
        }
        return true;
    }
};