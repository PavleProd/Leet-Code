#include <bits/stdc++.h>

using namespace std;

int maxChars(const string& s, int k, char maxChar) {
    int cnt[26] = {};
    cnt[s[0] - 'A'] = 1;
    int maxLen = 1;
    int left = 0, right = 0;
    while(right < s.size()) {
        int numElements = right - left + 1;
        if(numElements - cnt[maxChar - 'A'] > k) { // vise elemenata nego sto mozemo zameniti
            cnt[s[left] - 'A']--;
            left++;
        }
        else {
            maxLen = max(maxLen, numElements);
            right++;
            if(right < s.size()) {
                cnt[s[right] - 'A']++;
            }
        }
    }
    return maxLen;
}

int characterReplacement(const string& s, int k) {
    if(s.empty()) return 0;

    int maxLen = 0;
    for(char c = 'A'; c <= 'Z'; c++) {
        maxLen = max(maxLen, maxChars(s, k, c));
    }

    return maxLen;
}

int characterReplacementFaster(const string& s, int k) {
    if(s.empty()) return 0;
    int cnt[26] = {};
    char maxChar = s[0];
    int maxLen = 1;
    int left = 0, right = 0;
    string maxS;
    while(right < s.size()) {
        cnt[s[right] - 'A']++;
        if(cnt[s[right] - 'A'] > cnt[maxChar - 'A']) {
            maxChar = s[right];
        }
        int numElements = right - left + 1;
        if(numElements - cnt[maxChar - 'A'] > k) { // vise elemenata nego sto mozemo zameniti
            cnt[s[left] - 'A']--;
            left++;
        }
        else {
            if(maxLen < numElements) {
                maxS = s.substr(left, right - left + 1);
            }
            maxLen = max(maxLen, numElements);
        }
        right++;
    }
    cout << maxS << "\n";
    return maxLen;
}

/*int main() {
    string s = "BAAA";
    cout << characterReplacementFaster(s, 0);
}*/
