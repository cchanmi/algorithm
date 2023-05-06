#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100001

long n, l;
vector<pair<long, long>> hole;

void input() {
    cin >> n >> l;
    long a, b;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        hole.push_back({a, b});
    }
    sort(hole.begin(), hole.end());
}

long greedy() {
    long result = 0;
    long stickEnd = 0;
    long stickNum;
    for(int i=0; i<n; i++) {
        if ( stickEnd <= hole[i].first) {
            if ((hole[i].second - hole[i].first)%l == 0) {
                stickNum = (hole[i].second - hole[i].first) / l;
            } else {
                stickNum = (hole[i].second - hole[i].first)/l + 1;
            }
            result += stickNum;
            stickEnd = hole[i].first + l*stickNum;
        } else {
            if (hole[i].second < stickEnd) continue;
            if ((hole[i].second - stickEnd)%l == 0) {
                stickNum = (hole[i].second - stickEnd) / l;
            } else {
                stickNum = (hole[i].second - stickEnd)/l + 1;
            }
            result += stickNum;
            stickEnd = stickEnd + l*stickNum;
        }
    }
    return result;
}

int main() {
    FAST;
    input();
    cout << greedy() << "\n";
}

