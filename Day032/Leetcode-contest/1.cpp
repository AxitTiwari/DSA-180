#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string concatMappedChars;

        for (int i = 0; i < words.size(); i++) {

            string word = words[i];
            
            int sumOfChars = 0;
            for (auto i : word) {
                sumOfChars += weights[i-'a'];
            }
            
            int mappedValue = sumOfChars % 26;

            int revMappedValue = 25 - mappedValue;

            concatMappedChars.push_back(revMappedValue + 'a');  
        }
        return concatMappedChars;
    }
};