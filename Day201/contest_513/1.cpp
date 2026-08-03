
// https://leetcode.com/contest/weekly-contest-513/problems/maximize-pair-strength-using-gcd/

// class Solution {
// public:
//     long long maxPairStrength(vector<int>& nums) {

//         long long res = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             long long ans = 0;
//             for (int j = i+1; j < nums.size(); j++) {

//                 long long prod = 1LL * nums[i] * nums[j];
//                 long long divisor = 1LL * gcd(nums[i], nums[j]) * gcd(nums[i], nums[j]);
//                 ans = ans > prod / divisor ? ans : prod / divisor;
//             }
//             res = res > ans ? res : ans;
//         }
//         return res;
//     }
// private:
//     int gcd(int a, int b) {

//         while (b != 0) {
//             int rem = a % b;
//             a = b;
//             b = rem;
//         }
//         return a;
//     }
// };©leetcode