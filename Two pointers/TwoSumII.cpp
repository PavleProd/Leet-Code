#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum2(vector<int>& numbers, int target) {
    int begin = 0, end = numbers.size() - 1;
    while(begin < end) {
        int sum = numbers[begin] + numbers[end];
        if(sum == target) {
            return {begin + 1, end + 1}; // 1 - indexed
        }
        else if(sum > target) {
            end--;
        }
        else {
            begin++;
        }
    }

    return {};
}
