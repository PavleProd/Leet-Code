#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string& s, string& t) { // O(nlogn) time, O(1) space
    if(s.size() != t.size()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

bool isAnagramFaster(string& s, string& t) { // O(1) time, O(1) space
    if(s.size() != t.size()) return false;

    int frequency[26] = {0};

    for(int i = 0 ; i < s.size(); i++) {
        frequency[s[i] - 'a']++;
        frequency[t[i] + 'a']--;
    }

    return all_of(frequency, frequency + 26, )
}

int main() {
    string s = "test";
    string t = "stee";
    cout << isAnagramFaster(s, t);
}