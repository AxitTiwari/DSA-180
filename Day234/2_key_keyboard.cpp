// https://leetcode.com/problems/2-keys-keyboard/submissions/2131032577

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {

        if (n == 1) return 0;
        
        return 1 + f(1, 1, n);
    }
private:
    int f(long long screen, long long clipboard, int n) {

        if (screen == n) return 0;

        if (screen > n) return 1e9 / 2;

        int copy_paste = 2 + f(screen*2, screen, n);
        int paste = 1 + f(screen+clipboard, clipboard, n);

        return min(copy_paste, paste);
    }
};