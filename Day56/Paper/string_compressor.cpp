#include <iostream>
#include <string>

using namespace std;

void compress(string &s, string &compress_s) {

    int i = 0;
    int cnt = 1;
    while (i < s.length()-1) {

        // a a a b c c j j
        if (s[i] == s[i+1]) {
            cnt++;
        }
        else {
            // push char
            compress_s.push_back(s[i]);

            if (cnt > 1) {
                char count = cnt + '0';
                compress_s.push_back(count);
                cnt = 1;
            }
        }
        i++;
    }

    compress_s.push_back(s[i]);
    if (cnt > 1) {
        char count = cnt + '0';
        compress_s.push_back(count);
    }
}


int main() {
    
    string s;
    cin >> s;

    string compress_s;
    compress(s, compress_s);

    cout << compress_s;

    return 0;
}