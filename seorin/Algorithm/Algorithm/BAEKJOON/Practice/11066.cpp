#include <bits/stdc++.h>
using namespace std;
#define FASE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MAX 501
#define MAX_COST 10000

int t;
int k;
int num[MAX];
int cost[MAX][MAX];
int sum[MAX];

void input() {
    memset(num, 0, sizeof(num));
    memset(cost, 0, sizeof(cost));
    sum[0] = 0;
    cin >> k;
    for(int i=1; i<=k; i++) {
        cin >> num[i];
        sum[i] = sum[i-1] + num[i];
        for(int j=i+1; j<=k; j++) {
            cost[i][j] = MAX_COST * MAX;
        }
        cost[i][i] = 0;
    }
}

int solve() {
    for(int i=1; i<k; i++) {
        for(int j=1; j<=k-i; j++) {
            for (int l=0; l<i; l++) {
                if (cost[j][j+l]+cost[j+l+1][j+i]+sum[j+i]-sum[j-1] < cost[j][j+i]) {
                    cost[j][j+i] = cost[j][j+l]+cost[j+l+1][j+i]+sum[j+i]-sum[j-1];
                } else {
                    cost[j][j+i] = cost[j][j+i];
                }
            }
        }
    }
    return cost[1][k];
}
int main() {
    cin >> t;
    while (t--)
    {
        input();
        cout << solve() << "\n";
    }
}