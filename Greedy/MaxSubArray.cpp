#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
    vector<int> sum0toI(nums.size() + 1);
    sum0toI[0] = 0;
    int sum = 0, sum2 = 0;
    int maxVal = nums[0], maxI = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        sum2 += nums[i];
        sum0toI[i + 1] = sum;
        if(sum2 < 0) {
            sum2 = 0;
        }
        else if(sum2 > maxVal) {
            maxVal = sum2;
            maxI = i;
        }
    }

    if(maxVal < 0) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxVal) {
                maxVal = nums[i];
                maxI = i;
            }
        }
    }

    int maxSum = INT_MIN;
    for(int i = 0; i <= maxI; i++) {
        maxSum = max(sum0toI[maxI + 1] - sum0toI[i], maxSum);
    }

    return maxSum;
}

int maxSubArrayFaster(vector<int>& nums) {
    int sum = 0, maxVal = INT_MIN;
    for(int i = 0 ; i < nums.size(); i++) {
        sum += nums[i];
        if(sum > maxVal) {
            maxVal = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }

    return maxVal;
}

/*int main() {
    vector<int> nums{-2, -1};
    cout << maxSubArray(nums);
}*/
