#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100001

long long n, m;
long parent[MAX];
int roadNum = 0;
vector<pair<long, pair<long, long>>> v;

int getParent(long num) {
    if (parent[num] == num) return num;
    else return parent[num] = getParent(parent[num]);
}

void unionParent(long a, long b) {
    if ( getParent(a) < getParent(b)) { parent[getParent(b)] = getParent(a);
    } else parent[getParent(a)] = getParent(b);
}

int mst() {
    int result = 0, i = -1;
    sort(v.begin(), v.end());
    while (roadNum < n-2) {
        i++;
        pair<long, long> road = v[i].second;
        if (getParent(road.first) != getParent(road.second)) {
            result += v[i].first;
            unionParent(road.first, road.second);
            roadNum++;
        }
    }
    return result;
}

int main() {
    FAST;
    cin >> n >> m;
    for(int i=0; i<=n; i++) {
        parent[i] = i;
    }
    while (m--) {
        int startPoint, endPoint, charge;
        cin >> startPoint >> endPoint >> charge;
        v.push_back({charge, {startPoint, endPoint}});
    }
    cout << mst() << "\n";
}
