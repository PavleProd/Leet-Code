#include <bits/stdc++.h>

using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<>> pq;
    int k;
public:
    KthLargest(int k, const vector<int>& nums) {
        this->k = k;
        for(int i = 0; i < nums.size(); i++) {
            if(i < k) {
                pq.push(nums[i]);
            }
            else if(pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }

    int add(int val) {
        if(pq.size() < k) {
            pq.push(val);
        }
        else if(pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/*int main() {
    KthLargest kthLargest = KthLargest(2, {0});
    cout << kthLargest.add(-1);
    cout << "\n" << kthLargest.add(1);
    cout << "\n" << kthLargest.add(-2);
    cout << "\n" << kthLargest.add(-4);
    cout << "\n" << kthLargest.add(3);
}*/
