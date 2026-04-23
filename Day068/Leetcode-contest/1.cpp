#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        // check for even
        bool is_array_even = false;
        for (int i = 0; i < nums1.size(); i++) {

            // if odd number occurs
            if (nums1[i] & 1) {

                // make it even, we need a odd number
                bool odd_found = false;
                for (int j = 0; j < nums1.size(); j++) {

                    if (i != j && nums1[j] & 1) {
                        odd_found = true;
                        break;
                    }
                }

                if (!odd_found) {
                    break;
                }
            }

            // we executed last element
            if (i == nums1.size() - 1) {
                is_array_even = true;
            }
        }

        if (is_array_even) return true;

                
        // check for odd
        bool is_array_odd = false;
        for (int i = 0; i < nums1.size(); i++) {

            // if even number occurs
            if (!(nums1[i] & 1)) {

                // make it odd, we need a odd number
                bool odd_found = false;
                for (int j = 0; j < nums1.size(); j++) {

                    if (i != j && nums1[j] & 1) {
                        odd_found = true;
                        break;
                    }
                }

                if (!odd_found) {
                    break;
                }
            }

            // we executed last element
            if (i == nums1.size() - 1) {
                is_array_odd = true;
            }
        }

        if (is_array_odd) return true;

        return false;
    }
};