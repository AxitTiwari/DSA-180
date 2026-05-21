// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/submissions/2008593227

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[10];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;

        for (int i = 0; i <= 9; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie(char ch) {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word) {

        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // assumption, word will be in uppercase
        int index = word[0] - '0';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root, word);
    }

    int lcp(string str) {

        int ans = 0;

        TrieNode* temp = root;
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];

            int index = ch - '0';

            if (temp->children[index] != NULL) {
                ans++;
                temp = temp->children[index];
            }
            else {
                break;
            }
            
        }
        return ans;
    }
};


class Solution {
private:
    int f(int a, int b) {

        string digit1 = to_string(a);
        string digit2 = to_string(b);

        int count = 0;
        for (int i = 0; i < digit1.length(); i++) {

            if (digit1[i] == digit2[i]) {
                count++;
            }
            else {
                break;
            }
        }
        return count;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        Trie trie = Trie('\0');

        for (int a : arr2) {

            string num = to_string(a);
            trie.insert(num);
        }

        int count = 0;
        for (int a : arr1) {
            string num = to_string(a);
            count = max(count, trie.lcp(num));
        }
        return count;
    }
};