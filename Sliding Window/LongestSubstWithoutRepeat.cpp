#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> isPresent;
    int left = 0, right = 0;
    int maxSubstring = 0;
    while(right < s.size()) {
        if(isPresent[s[right]]) {
            isPresent[s[left]]--;
            left++;
        }
        else {
            isPresent[s[right]]++;
            maxSubstring = max(right - left + 1, maxSubstring);
            right++;
        }
    }

    return maxSubstring;
}

/*int main() {
    string s = " 1234444";
    cout << lengthOfLongestSubstring(s);
}*/
