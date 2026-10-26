#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {

        long long res = 0;
        for (auto num : nums) res += num;

        vector<int> tmp;
        for (auto num : nums) {

            int new_num = rearranged_num(num);
            int diff = new_num - num;
            diff = diff < 0 ? 0 : diff;

            // cout << num << " " << new_num << endl;
            tmp.push_back(diff);
        }

        sort(tmp.rbegin(), tmp.rend());

        for (int i = 0; i < k; i++) {
            res += tmp[i];
        }
        return res;
    }
private:
    int rearranged_num(int num) {

        vector<int> cnt(10, 0);
        while (num > 0) {
            int digit = num % 10;
            cnt[digit]++;
            num = num / 10;
        }

        int new_num = 0;
        for (int i = 9; i >= 0; i--) {

            if (cnt[i] == 0) continue;

            while (cnt[i] != 0) {
                new_num = new_num * 10 + i;
                cnt[i]--;
            }
        }
        return new_num;
    }
};