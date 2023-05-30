#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    auto cmp = [](const pair<double, int>& p1, const pair<double,int>& p2) {
        return p1.first < p2.first;
    };
    priority_queue<pair<double,int>, vector<pair<double,int>>, decltype(cmp)> pq(cmp); // [udaljenost od centra,indeks u vektoru]
    for(int i = 0; i < points.size(); i++) {
        double dst = hypot(points[i][0], points[i][1]);
        if(i < k) {
            pq.push({dst, i});
            continue;
        }

        double kthDistance = pq.top().first;
        if(kthDistance > dst) {
            pq.pop();
            pq.push({dst, i});
        }

    }
    vector<vector<int>> minKElements;
    while(!pq.empty()) {
        int index = pq.top().second;
        pq.pop();
        minKElements.emplace_back(points[index]);
    }

    return minKElements;
}

/*int main() {
    vector<vector<int>> points{{3,3}, {5,-1}, {-2,4}};
    vector<vector<int>> res = kClosest(points, 2);

    for(const auto& point : res) {
        cout << point[0] << " " << point[1] << "\n";
    }
}*/
