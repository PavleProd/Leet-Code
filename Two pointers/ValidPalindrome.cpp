#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(const string& s) {
    unsigned int left = 0, right = s.size() - 1;

    while(left < right) {
        if(!isalnum(s[left])) {
            left++;
            continue;
        }
        if(!isalnum(s[right])) {
            right--;
            continue;
        }

        if(tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}