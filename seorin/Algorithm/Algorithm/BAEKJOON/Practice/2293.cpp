#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100001

int n, k;
vector<int> coin;

int value[10001];

void input() {
    cin >> n >> k;
    int m;
    coin.push_back(0);
    for(int i=0; i<n; i++) {
        cin >> m;
        coin.push_back(m);
    }
    sort(coin.begin(), coin.end());
    memset(value, 0, sizeof(value));
}

void solve() {
    for(int i=0; i<n; i++) {
        value[0] = 1;
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=k; j++) {
            if (j-coin[i] >=0) {
                value[j] = value[j] + value[j-coin[i]];
            }
        }
    }
}

int main() {
    FAST;
    input();
    solve();
    cout << value[k] << "\n";
}

