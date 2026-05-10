#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    bool is_valid(string& s, int i) {

        if (i > 0 && i < s.size()-1 && islower(s[i-1]) && islower(s[i+1])) {
            return true;
        }
        return false;
    }
    
    vector<int> count_word(vector<string>& queries, string& concat) {

        unordered_map<string, int> count_words;
        string word;
        for (int i = 0; i < concat.length(); i++) {

            char ch = concat[i];

            if (islower(ch)) {
                word += ch;
            }
            else if (ch == '-' && is_valid(concat, i)) {
                word += ch;
            }
            else {

                // seperator
                if (!word.empty()) {
                    count_words[word]++;
                    word.clear();
                }
            }
        }

        if (!word.empty()) {
            count_words[word]++;
        }

        vector<int> ans;
        for (auto q : queries) {
            ans.push_back(count_words[q]);
        }
        
        return ans;
    }
    
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {

        // pattern: word count not string matching
        
        string concat;
        for (auto c : chunks) {
            concat += c;
        }
        cout << concat;

        vector<int> ans = count_word(queries, concat);
        return ans;
    }
};