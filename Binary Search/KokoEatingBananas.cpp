#include <bits/stdc++.h>

using namespace std;

bool isValid(vector<int>& piles, int h, int k) {
    for(int pile: piles) {
        h -= pile / k + (pile%k!=0);
        if(h < 0)  {
            return false;
        }
    }
    return true;
}

// ako broj k ispunjava uslov iz zadatka onda ce svi brojevi k+1,k+2,... ispunjavati uslov, pa binarnom pretragom
// trazimo minimalno takvo k
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = 0;
    for(int pile: piles) {
        if(pile > high) {
            high = pile;
        }
    }

    int minK = high;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isValid(piles, h, mid)) {
            minK = min(minK, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return minK;
}

/*int main() {
    vector<int> piles{30,11,23,4,20};
    cout << minEatingSpeed(piles, 6);
}*/
