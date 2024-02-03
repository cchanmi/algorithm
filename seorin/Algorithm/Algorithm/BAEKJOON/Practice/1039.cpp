#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 9999999

int  n, k;
int num[7];
int idx;
int result;
set<pair<int, int>> visited;


void input() {
    cin >> n >> k;
    idx = -1;
    result = 0;
    while(n > 0) {
        idx++;
        num[idx] = n%10;
        n /= 10;
    }
}

int getNum() {
    int result = 0;
    for (int i=idx; i>=0; i--) {
        result *= 10;
        result += num[i];
    }
    return result;
}

int bfs(int k) {
    if (k==0) {
        return getNum();
    } else {
        for (int i=idx; i>=1; i--) {
            for (int j=i-1; j>=0; j--) {
                swap(num[i], num[j]);
                if (visited.find(make_pair(getNum(), k)) == visited.end()) {
                    visited.insert(make_pair(getNum(), k));
                    result = max(result, bfs(k-1));
                }
                swap(num[i], num[j]);
            }
        }
        return result;
    }
}

int solve() {
    if (idx == 0) {
        return -1;
    } else if (idx == 1) {
        if (num[0] == 0) return -1;
    }
    return bfs(k);
}

int main() {
    FAST;
    input();
    cout << solve() << "\n";
}