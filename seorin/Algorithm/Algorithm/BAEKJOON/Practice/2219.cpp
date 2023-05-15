#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 201

int n, m;
vector<pair<int, int>> line[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> result;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minDist;
bool visited[MAX];
int dist[MAX];


void input() {
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        line[a].push_back({b, c});
        line[b].push_back({a, c});
    }
}

void solve() {
    for(int i=1; i<=n; i++) {
        int sum = 0, lineNum=0;
        while (!minDist.empty()) minDist.pop();
        for(int j=1; j<=n; j++) dist[j] = INT_MAX;
        memset(visited, false, sizeof(bool)*(n+1));
        visited[i] = true;
        dist[i] = 0;
        lineNum++;
        for(int j=0; j<line[i].size(); j++)
            minDist.push({line[i][j].second, line[i][j].first});
        while (lineNum<=n && !minDist.empty()) {
            int curLocation = minDist.top().second;
            int curDist = minDist.top().first;
            minDist.pop();
            if (visited[curLocation]) continue;
            lineNum++;
            visited[curLocation] = true;
            sum += curDist;
            for(int j=0; j<line[curLocation].size(); j++) {
                if (visited[line[curLocation][j].first]) continue;
                minDist.push({curDist + line[curLocation][j].second, line[curLocation][j].first});
            }
        }
        result.push({sum, i});
    }
}

int main() {
    FAST;
    input();
    solve();
    cout << result.top().second << "\n";
}

