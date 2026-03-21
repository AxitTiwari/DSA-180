#include <iostream>
#include <vector>

// wronge output mil raha hai, esko fir kr lena (leetcode 88)
using namespace std;

class Solution {
public:

    vector <int> shift(vector <int> nums, int idx, int m) {

        int curr = m + 1;

        while (curr != idx) {

            nums[curr--] = nums[curr-1];
        }

        return nums;
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = 0, j = 0;
        int size = m;

        for (int i = 0; i < m+n && j < n; i++) {

            cout << nums1[i] << " ";

            if (nums1[i] < nums2[j]) {

                nums1 = shift(nums1, i+1, size);
                
                nums1[i+1] = nums2[j];
                i++;
                size++;
            }
            else {

                nums1 = shift(nums1, i, size);

                nums1[i] = nums2[j];
                j++;
                size++;
            }
        } 
    }
};

int main() {

    vector <int> nums1 = {1, 2, 3, 0, 0, 0};
    vector <int> nums2 = {2, 5, 6};

    int m = 3, n = 3;

    Solution obj;
    obj.merge(nums1, m, nums2, n);

    cout << "hi";

    for (int i = 0; i < nums1.size(); i++) {

        cout << nums1[i] << " ";
    }

    return 0;
}