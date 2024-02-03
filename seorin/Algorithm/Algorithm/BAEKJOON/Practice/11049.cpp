#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 501

int n;
vector<pair<int, int>> num;
long result[MAX][MAX];

void input() {
    cin >> n;
    int a,b;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        num.push_back({a, b});
    }
    memset(result, -1, sizeof(result));
    for(int i=0; i<n; i++) {
        result[0][i] = 0;
        result[1][i] = 0;
    }
}

void solve() {
    for(int i=2; i<=n; i++) {
        for(int j=0; j<=n-i; j++) {
            for(int k=1; k<i; k++) {
                if (result[i][j] == -1) result[i][j] == INT_MAX;
                result[i][j] = min(result[i][j], result[k][j] + result[i-k][j+k] + num[j].first*num[j+k-1].second*num[j+i-1].second);
            }
            for(int a=0; a<n; a++) {
                for(int b=0; b<n; b++) {
                    cout << result[a][b];
                }
                cout << "\n";
            }
            cout << "\n\n";
        }
    }
}

int main() {
    FAST;
    input();
    solve();
    cout << result[n][0] << "\n";
}

