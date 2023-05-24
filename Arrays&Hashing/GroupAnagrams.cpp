#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) { // O(NKlogK) time N- vector size, K- string len O(NK) space
    vector<vector<string>> res;
    vector<string> sorted = vector<string>(strs);
    for(auto & str : sorted) {
        sort(str.begin(), str.end());
    }

    unordered_map<string, vector<string>> groups;
    for(int i = 0; i < sorted.size(); i++) {
        if(groups.find(sorted[i]) == groups.end()) {
            groups[sorted[i]] = {strs[i]};
        }
        else {
            groups[sorted[i]].emplace_back(strs[i]);
        }
    }

    for(pair<string, vector<string>> group: groups) {
        res.emplace_back(group.second);
    }
    return res;
}

struct VectorHasher {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (int i : v) {
            hash ^= std::hash<int>{}(i);
        }
        return hash;
    }
};

struct VectorComparator {
    bool operator()(const vector<int>& v1, const vector<int>& v2) const {
        return v1 == v2;
    }
};


vector<vector<string>> groupAnagramsUnorderedMap(vector<string>& strs) { // O(NK) time, O(NK) space
    vector<vector<string>> res;
    vector<vector<int>> charCounts;

    unordered_map<vector<int>, vector<string>, VectorHasher, VectorComparator> groups;
    for(const string& str : strs) {
        vector<int> chars(26, 0);
        for(char chr: str) {
            chars[chr - 'a']++;
        }
        if(groups.find(chars) == groups.end()) {
            groups[chars] = {str};
        }
        else {
            groups[chars].emplace_back(str);
        }
    }


    for(const auto& group: groups) {
        res.emplace_back(group.second);
    }
    return res;
}