#include <bits/stdc++.h>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int, vector<int>> pq(stones.begin(), stones.end());

    while(pq.size() > 1) {
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        if(x != y) {
            pq.push(y - x);
        }
    }

    return pq.empty() ? 0 : pq.top();
}

/*int main() {
    vector<int> stones{};
    cout << lastStoneWeight(stones);
}*/
