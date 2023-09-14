#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_N 101
#define MAX_M  10000001
#define MAX_C 101

int n;
long m;
int maxCost;
long mem[MAX_N];
int cost[MAX_N];
long result[MAX_N][MAX_N*MAX_C];


void input() {
    maxCost = 0;
    memset(result[0], 0, sizeof(result[0][MAX_N*MAX_C]));
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> mem[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> cost[i];
        maxCost += cost[i];
    }
}
int solve() {
    int minCost = maxCost;
    for (int i=1; i<=n; i++) {
        for (int  j=0; j<=maxCost; j++) {
            if(j<cost[i]) {
                result[i][j] = result[i-1][j];
            } else {
                result[i][j] = max(result[i-1][j], result[i-1][j-cost[i]] + mem[i]);
            }
            if (m<=result[i][j]) {
                minCost = min(minCost, j);
            }
        }
    }
    return minCost;
}

int main() {
    input();
    cout << solve() << "\n";
}
