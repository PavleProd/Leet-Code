#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) { // O(nlogn) time, O(n) space
    vector<int> tVector = vector<int>(nums);
    sort(tVector.begin(), tVector.end());
    int begin = 0, end = tVector.size() - 1;
    int first = -1, second = -1;
    while(begin != end) {
        if(tVector[begin] + tVector[end] == target) {
            first = tVector[begin];
            second = tVector[end];
            break;
        }
        else if(tVector[begin] + tVector[end] > target) {
            end--;
        }
        else {
            begin++;
        }
    }

    vector<int> index(2, -1);
    for(int i = 0; i < nums.size(); i++) {
        if(index[0] == -1 && nums[i] == first) {
            index[0] = i;
        }
        else if(index[1] == -1 && nums[i] == second) {
            index[1] = i;
        }
    }

    return index;
}

vector<int> twoSumMap(vector<int>& nums, int target) { // O(n) time O(n) space
    unordered_map<int, int> complements;
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if(complements.find(complement) != complements.end()) {
            return {i, complements[complement]};
        }

        complements[nums[i]] = i;
    }

    return {-1, -1};
}