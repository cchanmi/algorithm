#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100001

int charge[1001][1001];
int result[1001];
int start, dest, moveCharge;
bool visited[1001];
int n, m;

void input() {
    memset(visited, false, sizeof(visited));
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            charge[i][j] = -1;
    }
    while (m--) {
        int first, second, moveCharge;
        cin >> first >> second >> moveCharge;
        if (charge[first][second] == -1)
            charge[first][second] = moveCharge;
        else
            charge[first][second] = min(charge[first][second], moveCharge);
    }
    cin >> start >> dest;
    for(int i=1; i<=n; i++) {
        if (charge[start][i] != -1) {
            result[i] = charge[start][i];
        } else result[i] = MAX*n;
    }
    result[start] = 0;
    visited[start] = true;
}

void dijkstra() {
    int minVal, minIdx;
    for(int i=0; i<n-2; i++) {
        minVal = MAX*n;
        for(int j=1; j<=n; j++) {
            if (visited[j]) {
                continue;
            } else {
                if (minVal > result[j]) {
                    minVal = result[j];
                    minIdx = j;
                }
            }
        }
        visited[minIdx] = true;
        for(int j=1; j<=n; j++) {
            if (visited[j]) {
                continue;
            } else {
                if (charge[minIdx][j] != -1)
                    result[j] = min(result[j], result[minIdx] + charge[minIdx][j]);
            }
        }
    }
}

int main() {
    FAST;
    input();
    dijkstra();
    cout << result[dest] << "\n";
}
