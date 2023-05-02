#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 801

int n, e;
vector<pair<int, int>> road[MAX];
bool visited[MAX];
int dist[MAX];
int v1, v2;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int calDist(int startPoint, int endPoint) {
    memset(visited, false, (n+1)*sizeof(bool));
    fill(dist, dist+n+2, INT_MAX);
    
    int minIdx = startPoint;
    dist[startPoint] = 0;
    pq.push({0, startPoint});
    while (!pq.empty()) {
        int cost = pq.top().first;
        minIdx = pq.top().second;
        pq.pop();
        if (minIdx == endPoint) break;
        if (visited[minIdx]) continue;
        visited[minIdx] = true;
        for(int i=0; i<road[minIdx].size(); i++) {
            if (visited[road[minIdx][i].first]) continue;
            if (dist[road[minIdx][i].first] > cost + road[minIdx][i].second) {
                dist[road[minIdx][i].first] = cost + road[minIdx][i].second;
                pq.push({dist[road[minIdx][i].first], road[minIdx][i].first});
            }
        }
    }
    return dist[endPoint];
}

void input() {
    cin >> n >> e;
    int start, end, charge;
    for(int i=1; i<=n; i++) road[i].push_back({i, 0});
    while (e--) {
        cin >> start >> end >> charge;
        road[start].push_back({end, charge});
        road[end].push_back({start, charge});
    }
    cin >> v1 >> v2;
}

int main() {
    FAST;
    input();
    int fromStartToV1 = calDist(1, v1);
    int fromStartToV2 = calDist(1, v2);
    int v1ToV2 = calDist(v1, v2);
    int v1ToN = calDist(v1, n);
    int v2ToN = calDist(v2, n);
    if (fromStartToV1 == INT_MAX || fromStartToV2 == INT_MAX || v1ToV2 == INT_MAX || v1ToN == INT_MAX || v2ToN == INT_MAX) {
        cout << -1 << "\n";
        return 0;
    }
    if (fromStartToV1 + v1ToV2 + v2ToN < fromStartToV2 + v1ToV2 + v1ToN) {
        cout << fromStartToV1 + v1ToV2 + v2ToN << "\n";
    } else {
        cout << fromStartToV2 + v1ToV2 + v1ToN << "\n";
    }
        
}
