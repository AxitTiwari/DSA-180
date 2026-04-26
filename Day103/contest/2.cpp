
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool is_vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
public:
    string sortVowels(string s) {

        // map
        unordered_map<char, pair<int, int>> vowel_count; // (ch, (count, index))
        int i = 0;
        for (auto ch : s) {
            
            if(is_vowel(ch)) {
                
                if (vowel_count.find(ch) == vowel_count.end()) {
                    // first time seeing this character
                    vowel_count[ch] = {1, i};   // i = current index
                } else {
                    // already exists
                    vowel_count[ch].first++;    // only increment count
                }
            }
            i++;
        }

        // heap
        priority_queue<tuple<int, int, char>> max_heap; // (count > index, char)
        for (auto it : vowel_count) {

            int count = it.second.first;
            int index = it.second.second;
            char ch = it.first;

            index = index == 0 ? 0 : -index;  // '-' is not a mistake
            max_heap.push({count, index, ch}); 
        }

        string ans;
        for (auto ch : s) {

            if (!is_vowel(ch)) {
                ans += ch;
            }
            else {
                auto [cnt, idx, vowel_to_push] = max_heap.top();

                // cout << "cnt: " << cnt << endl;
                // cout << "idx: " << idx << endl;
                // cout << "ch: " << vowel_to_push << endl;

                ans += vowel_to_push;

                // decrement the count 
                vowel_count[vowel_to_push].first--;

                if (vowel_count[vowel_to_push].first == 0) {
                    max_heap.pop();
                }
            }
        }
        return ans;
    }
};