#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio,cin.tie(0), cout.tie(0)

#define MAX_N 101
#define MAX_M 1001
#define MAX 100001

int n, k;
int w[MAX_N];
int v[MAX_N];
int result[MAX_N][MAX];

void input() {
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> w[i] >> v[i];
    for (int i=1; i<=k; i++) result[0][i] = 0;
    for (int i=1; i<=n; i++) result[i][0] = 0;
}

int solve() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            if (j < w[i]) {
                result[i][j] = result[i-1][j];
            } else  {
                result[i][j] = max(result[i-1][j], result[i-1][j-w[i]] + v[i]);
            }
        }
    }
    return result[n][k];
}

int main() {
    input();
    cout  <<solve() << "\n";
}