#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
    vector<int> maxToTheRight(prices.size());
    int currMax = 0;
    for(int i = prices.size() - 1; i >= 0; i--) {
        maxToTheRight[i] = currMax;
        if(prices[i] > currMax) {
            currMax = prices[i];
        }
    }

    currMax = 0;
    for(int i = 0; i < prices.size(); i++) {
        currMax = max(maxToTheRight[i] - prices[i], currMax);
    }

    return currMax;
}

/*
int main() {
    vector<int> prices{};
    cout << maxProfit(prices);
}
*/
