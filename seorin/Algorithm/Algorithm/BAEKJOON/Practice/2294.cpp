#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX  10001

int n, k;
int result[MAX];
vector<int> coin;
    
void input() {
    cin >> n >> k;
    int m;
    for(int i=0; i<n; i++) {
        cin >> m;
        coin.push_back(m);
    }
    sort(coin.begin(), coin.end());
    memset(result, -1, sizeof(result));
}

void solve() {
    result[0] = 0;
    for(int i=1; i<=k; i++) {
        for(int j=0; j<n; j++) {
            if (i-coin[j] >=0 && result[i-coin[j]] != -1) {
                if (result[i] == -1) {
                    result[i] = result[i-coin[j]]+1;
                } else {
                    result[i] = min(result[i], result[i-coin[j]]+1);
                }
            }
        }
    }
}

int main() {
    FAST;
    input();
    solve();
    cout << result[k] << "\n";
}

