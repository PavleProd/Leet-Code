#include <bits/stdc++.h>

using namespace std;

bool isValid(const string& s) {
    stack<char> brackets;
    unordered_set<char> openBrackets{'(', '[', '{'};
    map<char, char> closedBrackets{
        {')','('},
        {']', '['},
        {'}', '{'}
    };
    for(char c : s) {
        if(openBrackets.find(c) != openBrackets.end()) {
            brackets.push(c);
        }
        else {
            if(brackets.empty()) return false;
            if(closedBrackets[c] != brackets.top()) {
                return false;
            }

            brackets.pop();
        }
    }

    return brackets.empty();
}