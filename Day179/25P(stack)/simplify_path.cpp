// https://leetcode.com/problems/simplify-path/submissions/2063874451

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        
        stringstream ss(path);

        vector<string> components;
        string part;
        while (getline(ss, part, '/')) {
            components.push_back(part);
        }

        deque<string> s; // used as a stack
        for (auto &component : components) {

            if (component == "." || component == "") continue;

            if (component == "..") {
                if (!s.empty()) s.pop_back();
            }
            else {
                s.push_back(component);
            }
        }

        if (s.empty()) return "/";

        string res;
        for (string path : s) {
            res += "/" + path;
        }
        return res;
    }
};