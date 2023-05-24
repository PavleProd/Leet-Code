#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    if(nums.empty()) {
        return false;
    }
    sort(nums.begin(), nums.end());

    int last = -1;
    for(int num: nums) {
        if(last == num) {
            return true;
        }
        last = num;
    }
    return false;
}

bool containsDuplicateSet(vector<int>& nums) {
    unordered_set<int> numSet;
    for(int num: nums) {
        numSet.insert(num);
    }

    return numSet.size() != nums.size();
}