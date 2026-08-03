// class Solution {
// public:
//     int countRatioSubarrays(vector<int>& nums, int a, int b) {

//         vector<int> even_num;
//         vector<int> odd_num;

//         even_num.push_back(0);
//         odd_num.push_back(0);
        
//         int even = 0, odd = 0;
//         for (int num : nums) {

//             if (num & 1) {
//                 odd++;
//             }
//             else {
//                 even++;
//             }
//             even_num.push_back(even);
//             odd_num.push_back(odd);
//         }

//         int res = 0;
//         for (int i = 0; i < nums.size(); i++) {

//             // subarray
//             for (int j = i; j < nums.size(); j++) {

//                 int even = even_num[j+1] - even_num[i];
//                 int odd = odd_num[j+1] - odd_num[i];

//                 if (
//                     odd_num[j+1] - odd_num[i] <= 0 ||
//                     even * b > odd * a
//                 ) continue;
//                 res += 1;
//             }
//         }
//         return res;
//     }
// };©leetcode