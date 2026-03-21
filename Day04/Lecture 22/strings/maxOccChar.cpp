#include <iostream>

char getMaxOccChareter(std::string s) {

    // array of count of each charecter
    int arr[26] = {0};

    for (int i = 0; i < s.length(); i++) {

        char ch = s[i];

        if (ch >= 'a' && ch <= 'z') {
            int charIdx = ch-'a';
            arr[charIdx]++;
        }
    }

    int max = -1, ans = -1;

    for (int i = 0; i < 26; i++) {
        
        if (max < arr[i]) {
            ans = i;
            max = arr[i];
        }
    }

    char result = 'a' + ans;
    return result;
}

int main() {

    std::string name;
    std::cout << "Enter a string: ";
    std::cin >> name;

    char result = getMaxOccChareter(name);

    std::cout << result << std::endl;

    return 0;
}